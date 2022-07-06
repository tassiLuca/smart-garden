#include <Arduino.h>
#include "LightingSystemImpl.h"

LightingSystemImpl::LightingSystemImpl(Light** lights): lights(lights) { 
    active = false;
}

void LightingSystemImpl::activate(const int brightnessIntensity) {
    int i;
    for (i = 0; i < 2; i++) {
        lights[i]->switchOn();
    }
    for (; i < 4; i++ ) {
        lights[i]->switchOn(map(brightnessIntensity, 0, 8, 0, 256));
    }
    active = true;
}

void LightingSystemImpl::deactivate() {
    for (int i = 0; i < 4; i++) {
        lights[i]->switchOff();
    }
    active = false;
}

bool LightingSystemImpl::isActive() {
    return active;
}
