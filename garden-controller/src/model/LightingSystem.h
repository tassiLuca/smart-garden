#ifndef __LIGHTING_SYSTEM__
#define __LIGHTING_SYSTEM__

class LightingSystem {

public:
    virtual void activate(int brightnessIntensity) = 0;

    virtual void deactivate() = 0;

    virtual bool isActive() = 0;

};

#endif