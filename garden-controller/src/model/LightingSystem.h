#ifndef __LIGHTING_SYSTEM__
#define __LIGHTING_SYSTEM__

class LightingSystem {

public:
    virtual void activate() = 0;

    virtual void setIntensity(int brightnessLevel);

    virtual void deactivate() = 0;

};

#endif