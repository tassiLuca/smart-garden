#ifndef __SIM_LIGHTING_SYSTEM__
#define __SIM_LIGHTING_SYSTEM__

#include "LightingSystem.h"

class SimulatedLightingSystem: public LightingSystem {

public:
    void activate(int brightnessIntensity) override;

    void deactivate() override;

    bool isActive() override;

private:
    bool active;

};

#endif