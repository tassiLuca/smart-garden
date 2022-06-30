#ifndef __TEMPERATURE_SENSOR_IMPL__
#define __TEMPERATURE_SENSOR_IMPL__

#include "TemperatureSensor.h"

class TemperatureSensorImpl: public TemperatureSensor 
{

private:
    int pin;

public:
    TemperatureSensorImpl(const int temperatureSensorPin);
    float getValue() override;

};

#endif