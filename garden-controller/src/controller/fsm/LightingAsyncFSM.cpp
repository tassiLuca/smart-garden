#include "LightingAsyncFSM.h"
#include <ArduinoJson.h>
#include "../serialcomm/MsgService.h"
#include "../../uilities/Logger.h"

#define LIGHTNESS_THRESHOLD 5

LightingAsyncFSM::LightingAsyncFSM() {
    currentState = IDLE;
    MsgService.registerObserver(this);
}

void LightingAsyncFSM::handleEvent(Event* event) {
    if (Garden.getState() != ALARM) {
        int lightness = getLightness(event->getData());
        updateState(lightness);
    }
}

void LightingAsyncFSM::updateState(int lightnessLevel) {
    if (lightnessLevel < LIGHTNESS_THRESHOLD) {
        currentState = ACTIVE;
        Garden.getLightingSystem()->activate();
    } else {
        Garden.getLightingSystem()->deactivate();
        currentState = IDLE;
    }
}

int LightingAsyncFSM::getLightness(String data) {
    StaticJsonDocument<256> doc;
    int light = doc["data"]["lightness"];
    return light;
}
