#ifndef __ACTUATORS_FACTORY__
#define __ACTUATORS_FACTORY__

#include "light/Light.h"
#include "servo/ServoMotor.h"

class ActuatorsFactory {

public:
    
    virtual Light* createLight(const int buttonPin) const = 0;

    virtual ServoMotor* createServoMotor(const int servoMotorPin) const = 0;

};

#endif