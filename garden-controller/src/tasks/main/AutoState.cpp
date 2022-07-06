#include <ArduinoJson.h>
#include "AutoState.h"
#include "../../serialcomm/MsgService.h"
#include "AlarmState.h"

#define ALARM_TEMPERATURE_THRESHOLD 5

void AutoState::handle() {
    if (MsgService.isMsgAvailable()) {
        Msg* msg = MsgService.receiveMsg();
        checkTransitions(msg->getContent());
    }
}

void AutoState::checkTransitions(String rawData) {
    StaticJsonDocument<256> doc;
    deserializeJson(doc, rawData);
    if (doc["action"] == "add-data") {
        if (doc["data"]["temperature"] >= 5 && !Garden.getIrrigationSystem()->isActive()) {
            this->getTask()->stateTransition(new AlarmState());
        }
    }
    // if doc["action"] is ...
}
