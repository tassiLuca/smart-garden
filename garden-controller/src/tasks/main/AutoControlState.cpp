#include "AutoControlState.h"
#include <ArduinoJson.h>
#include "../../serialcomm/MsgService.h"
#include "IdleState.h"
#include "../../uilities/Logger.h"

#define ALARM_THRESHOLD 5
#define LIGHTS_ACTIVATION_THRESHOLD 5 
#define IRRIGATION_ACTIVATION_THRESHOLD 2

void AutoControlState::handle() {
    Logger::getLogger()->log("New service message");
    StaticJsonDocument<256> doc;
    Msg* msg = MsgService.receiveMsg();
    deserializeJson(doc, msg->getContent());
    int temperature = doc["temperature"];
    int lightness = doc["lightness"];
    delete msg;
    // sistema di allarme
    if (temperature >= ALARM_THRESHOLD) {
        Garden.setState(ALARM);
    } else {
        setupSystem(temperature, lightness);
    }
    this->getTask()->stateTransition(new IdleState());
}

void AutoControlState::setupSystem(int temperature, int lightness) {
    // accensione luci
    if (lightness < LIGHTS_ACTIVATION_THRESHOLD) {
        Garden.getLightingSystem()->activate(lightness);
    } else {
        Garden.getLightingSystem()->deactivate();
    }
    // accensione sistema irrigazione
    if (lightness < IRRIGATION_ACTIVATION_THRESHOLD) {
        Garden.getIrrigationSystem()->setState(ON);
        Garden.getIrrigationSystem()->setIrrigationSpeed(temperature);
    } else {
        Garden.getIrrigationSystem()->setState(OFF);
    }
}
