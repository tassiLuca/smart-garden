#include "MainAsyncFSM.h"
#include <ArduinoJson.h>
#include "../../uilities/Logger.h"

#define ALARM_TEMPERATURE_THRESHOLD 5

MainAsyncFSM::MainAsyncFSM() {
    currentState = AUTO;
    MsgService.init();
    MsgService.registerObserver(this);
}

void MainAsyncFSM::handleEvent(Event* event) {
    switch(currentState) {
        case AUTO:
            autoBehaviour(event);
            break;
        case MANUAL:
            break;
        case ALARM:
            break;
        default:
            Logger::getLogger()->log("ERROR: not ammissible event");
            break;
    }
}

void MainAsyncFSM::autoBehaviour(Event* event) {
    if (event->getType() == NEW_DATA_EVENT) { // new data from service
        checkTransitions(event->getData());
    } else { // state transition to MANUAL
    }
}

void MainAsyncFSM::checkTransitions(String data) {
    StaticJsonDocument<256> doc;
    deserializeJson(doc, data);
    int tempLevel = doc["data"]["temperature"];
    int lightLevel = doc["data"]["ligtness"];
    if (tempLevel >= ALARM_TEMPERATURE_THRESHOLD) {
        currentState = ALARM;
    } else {
        // activate other tasks
    }
}

String MainAsyncFSM::getId() {
    return "MAIN-AFSM";
}
