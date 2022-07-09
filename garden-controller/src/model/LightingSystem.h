#ifndef __LIGHTING_SYSTEM__
#define __LIGHTING_SYSTEM__

class LightingSystem {

public:
    virtual void activate(const int brightnessIntensity) = 0;

    virtual void deactivate() = 0;

    virtual bool isActive() = 0;

    virtual void setL1(bool active) = 0;

    virtual void setL2(bool active) = 0;

    virtual void setL3(int lightness) = 0;

    virtual void setL4(int lightness) = 0;

};

#endif