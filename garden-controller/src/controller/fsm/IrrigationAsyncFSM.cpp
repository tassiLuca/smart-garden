#include "IrrigationAsyncFSM.h"
#include <ArduinoJson.h>
#include "../serialcomm/MsgService.h"
#include "../../uilities/Logger.h"

#define LIGHTNESS_THRESHOLD 2

IrrigationAsyncFSM::IrrigationAsyncFSM(SmartGarden* garden): AsyncFSM(garden) {
    MsgService.registerObserver(this);
}

void IrrigationAsyncFSM::handleEvent(Event* event) {
    // StaticJsonDocument<256> doc;
    // deserializeJson(doc, event->getData());
    // if (garden->getState() == AUTO && doc["action"] == "add-data") {
    //     if (doc["data"]["lightness"] < LIGHTNESS_THRESHOLD) {
    //         garden->getIrrigationSystem()->irrigate();
    //     } else {
    //         garden->getIrrigationSystem()->stop();
    //     }
    // }
    // if Garden.getState() == MANUAL && doc["action"] == "manual-control"
}
