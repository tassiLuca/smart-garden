#include <Arduino.h>
#include "LightingSystemImpl.h"
#include "../uilities/Logger.h"

LightingSystemImpl::LightingSystemImpl(Light* l1, Light* l2, Light* l3, Light* l4) { 
    this->l1 = l1;
    this->l2 = l2;
    this->l3 = l3;
    this->l4 = l4;
    active = false;
}

void LightingSystemImpl::activate(const int brightnessIntensity) {
    l1->switchOn();
    l2->switchOn();
    int intensity = map(brightnessIntensity, 4, 0, 0, 256);
    // Logger::getLogger()->log("LI " + String(intensity));
    l3->switchOn(intensity);
    l4->switchOn(intensity);
    active = true;
}

void LightingSystemImpl::deactivate() {
    l1->switchOff();
    l2->switchOff();
    l3->switchOff();
    l4->switchOff();
    active = false;
}

bool LightingSystemImpl::isActive() {
    return active;
}
