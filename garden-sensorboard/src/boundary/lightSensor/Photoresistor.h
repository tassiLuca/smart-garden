#ifndef __PHOTORESISTOR__
#define __PHOTORESISTOR__

#include "LightSensor.h"

class Photoresistor: public LightSensor {

private:
    int pin;

public:
    Photoresistor(const int photoresistorPin);
    int readValue() override;

};

#endif