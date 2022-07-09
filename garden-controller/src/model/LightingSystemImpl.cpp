#include <Arduino.h>
#include "LightingSystemImpl.h"

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

void LightingSystemImpl::setL1(bool active) {
    if (active) {
        l1->switchOn();
    } else {
        l1->switchOff();
    }
}

void LightingSystemImpl::setL2(bool active) {
    if (active) {
        l2->switchOn();
    } else {
        l2->switchOff();
    }
}

void LightingSystemImpl::setL3(int lightness) {
    l3->switchOn(lightness);
}

void LightingSystemImpl::setL4(int lightness) {
    l3->switchOn(lightness);
}
