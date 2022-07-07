#ifndef __LIGHTING_SYSTEM_IMPL__
#define __LIGHTING_SYSTEM_IMPL__

#include "../boundary/light/Light.h"
#include "LightingSystem.h"

class LightingSystemImpl: public LightingSystem {

public:
    LightingSystemImpl(Light* l1, Light* l2, Light* l3, Light* l4);
    void activate(const int brightnessIntensity) override;
    void deactivate() override;
    bool isActive() override;

private:
    Light* l1;
    Light* l2;
    Light* l3;
    Light* l4;
    int brightnessLevel;
    bool active;

};

#endif