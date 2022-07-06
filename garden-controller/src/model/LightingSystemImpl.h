#ifndef __LIGHTING_SYSTEM_IMPL__
#define __LIGHTING_SYSTEM_IMPL__

#include "../boundary/light/Light.h"
#include "LightingSystem.h"

class LightingSystemImpl: public LightingSystem {

public:
    LightingSystemImpl(Light** lights);
    void activate(const int brightnessIntensity) override;
    void deactivate() override;
    bool isActive() override;

private:
    Light** lights;
    int brightnessLevel;
    bool active;

};

#endif