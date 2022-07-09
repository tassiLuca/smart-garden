#include <ArduinoJson.h>
#include "AutoState.h"
#include "SendState.h"
#include "../../comm/SerialMsgService.h"

#define ALARM_THRESHOLD 5
#define LIGHTS_ACTIVATION_THRESHOLD 5 
#define IRRIGATION_ACTIVATION_THRESHOLD 2

void AutoState::handle() {
    StaticJsonDocument<256> doc;
    Msg* msg = MsgService.receiveMsg();
    deserializeJson(doc, msg->getContent());
    int temperature = doc["temperature"];
    int lightness = doc["lightness"];
    delete msg; // really important!
    if (temperature >= ALARM_THRESHOLD) {
        getTask()->Garden()->setState(ALARM);
    } else {
        setupLightnessSystem(lightness);
        setupIrrigationSystem(lightness, temperature);
    }
    this->getTask()->stateTransition(new SendState());
}

void AutoState::setupLightnessSystem(int lightness) {
    if (lightness < LIGHTS_ACTIVATION_THRESHOLD) {
        getTask()->Garden()->getLightingSystem()->activate(lightness);
    } else {
        getTask()->Garden()->getLightingSystem()->deactivate();
    }
}

void AutoState::setupIrrigationSystem(int lightness, int temperature) {
    if (lightness < IRRIGATION_ACTIVATION_THRESHOLD) {
        getTask()->Garden()->getIrrigationSystem()->setState(ON);
        getTask()->Garden()->getIrrigationSystem()->setIrrigationSpeed(temperature);
    } else {
        getTask()->Garden()->getIrrigationSystem()->setState(OFF);
    }
}
