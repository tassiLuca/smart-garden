#include "LightingSystemImpl.h"
#include <Arduino.h>
#include "../uilities/Logger.h"

#define DEFAULT_BRIGHNESS_LEVEL 5

LightingSystemImpl::LightingSystemImpl(Light** lights)
    : lights(lights) {
        this->brightnessLevel = DEFAULT_BRIGHNESS_LEVEL;
        lights[1]->switchOn();
}

void LightingSystemImpl::setIntensity(int brightnessLevel) {
    this->brightnessLevel = brightnessLevel;
}

void LightingSystemImpl::activate() {
    int i;
    for (i = 0; i < 2; i++) {
        lights[i]->switchOn();
    }
    for (; i < 4; i++ ) {
        lights[i]->switchOn(map(brightnessLevel, 0, 8, 0, 256));
    }
}

void LightingSystemImpl::deactivate() {
    for (int i = 0; i < 4; i++) {
        lights[i]->switchOff();
    }
}
