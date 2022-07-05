#include "MainAsyncFSM.h"
#include "../serialcomm/MsgService.h"
#include <ArduinoJson.h>

#define ALARM_THRESHOLD 5

MainAsyncFSM::MainAsyncFSM() {
    MsgService.init();
    MsgService.registerObserver(this);
}

void MainAsyncFSM::handleEvent(Event* event) {
    autoHandle(event->getData());
}

void MainAsyncFSM::autoHandle(String data) {
    StaticJsonDocument<256> doc;
    deserializeJson(doc, data);
    if (doc["action"] == "new-data") { // new data from service
        int temperature = doc["data"]["temperature"];
        if (temperature > ALARM_THRESHOLD && !Garden.getIrrigationSystem()->isActive()) {
            Garden.setState(ALARM);
        }
    } else if (doc["action"] == "update-state") {
        // if new state is MANUAL 
        {
            Garden.setState(MANUAL);
        } 
        // if new state is AUTO 
        {
            Garden.setState(AUTO);
        }
    } else if (doc["action"] == "manual-control") {

    }
}
