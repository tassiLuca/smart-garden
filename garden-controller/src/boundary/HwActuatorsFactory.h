#ifndef __HW_ACTUATORS_FACTORY__
#define __HW_ACTUATORS_FACTORY__

#include "ActuatorsFactory.h"

class HwActuatorsFactory: public ActuatorsFactory {

public:
    Light* createLight(const int lightPin) const;
    ServoMotor* createServoMotor(const int servoMotorPin) const;

};

#endif