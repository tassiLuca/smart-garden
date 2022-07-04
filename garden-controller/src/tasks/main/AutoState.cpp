#include "AutoState.h"
#include "../../uilities/Logger.h"
#include "../../serialcomm/MsgService.h"
#include "AlarmState.h"

#include <ArduinoJson.h>

#define MAX_TEMP_LEVEL 5

void AutoState::handle() {
    StaticJsonDocument<256> doc;
    if (MsgService.isMsgAvailable()) {
        Msg* msg = MsgService.receiveMsg();
        deserializeJson(doc, msg->getContent());
        if (doc["action"] == "add-data") {
            int temperatureLevel = doc["data"]["temperature"];
            int lightnessLevel = doc["data"]["lightness"];
            checkTransitions(temperatureLevel, lightnessLevel);
        } else if (doc["action"] == "change-state") {
            
        }
        delete msg;
    }
}

void AutoState::checkTransitions(int temperatureLevel, int lightnessLevel) {
    if (temperatureLevel >= MAX_TEMP_LEVEL && SmartGarden.getIrrigationSystem()->isActive()) {
        this->getTask()->stateTransition(new AlarmState());
    } else {
        
    }
}
