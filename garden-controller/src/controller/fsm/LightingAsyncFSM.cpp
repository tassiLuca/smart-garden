#include "LightingAsyncFSM.h"
#include <ArduinoJson.h>
#include <Arduino.h>
#include "../../uilities/Logger.h"

#define LIGHTNESS_THRESHOLD 5

LightingAsyncFSM::LightingAsyncFSM(SmartGarden* garden): AsyncFSM(garden) { }

void LightingAsyncFSM::handleEvent(Event* event) {
    Logger::getLogger()->log(event->getData());
    // StaticJsonDocument<256> doc;
    // String data = event->getData();

    // deserializeJson(doc, data);

    // if (garden->getState() == AUTO && doc["action"] == "add-data") {
    //     if (doc["data"]["lightness"] < LIGHTNESS_THRESHOLD) {
    //         garden->getLightingSystem()->activate();
    //     } else {
    //         garden->getLightingSystem()->deactivate();
    //     }
    // }
    // if Garden.getState() == MANUAL && doc["action"] == "manual-control"
}
