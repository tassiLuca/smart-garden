#ifndef __LED_H__
#define __LED_H__

#include "Light.h"

class Led: public Light {

public:
    Led(const int pinLed);
    void switchOn() override;
    void switchOff() override;

private:
    int pin;

};

#endif