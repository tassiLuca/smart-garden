#ifndef __LIGHTING_SYSTEM_IMPL__
#define __LIGHTING_SYSTEM_IMPL__

#include "LightingSystem.h"
#include "../boundary/light/Light.h"
#include <list>

class LightingSystemImpl: public LightingSystem {

public:
    LightingSystemImpl(Light** lights);
    void activate() override;
    void setIntensity(int brightnessLevel) override;
    void deactivate() override;

private:
    Light** lights;
    int brightnessLevel;

};

#endif