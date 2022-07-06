#include "MainAsyncFSM.h"
#include "../../uilities/Logger.h"
#include <ArduinoJson.h>

#define ALARM_THRESHOLD 5

MainAsyncFSM::MainAsyncFSM(SmartGarden* garden): AsyncFSM(garden) { }

void MainAsyncFSM::handleEvent(Event* event) {
    // StaticJsonDocument<256> doc;
    // deserializeJson(doc, event->getData());
    // if (garden->getState() == AUTO && doc["action"] == "add-data") { // new data from service
    //     int temperature = doc["data"]["temperature"];
    //     if (temperature > ALARM_THRESHOLD && !garden->getIrrigationSystem()->isActive()) {
    //         garden->setState(ALARM);
    //     }
    // } else if (doc["action"] == "update-state") {
    //     // if new state is MANUAL 
    //     {
    //         garden->setState(MANUAL);
    //     } 
    //     // if new state is AUTO 
    //     {
    //         garden->setState(AUTO);
    //     }
    // } else if (doc["action"] == "manual-control") {

    // }
}
