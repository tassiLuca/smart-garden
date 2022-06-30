#ifndef __LED_H__
#define __LED_H__

#include "Light.h"

class Led: public Light {

private:
    int pin;

public:
    Led(const int pinLed);
    void switchOn() override;
    void switchOff() override;

};

#endif