#ifndef __SERVO_MOTOR_IMPL__
#define __SERVO_MOTOR_IMPL__

#include <ServoTimer2.h>
#include "ServoMotor.h"

class ServoMotorImpl: public ServoMotor {

private:
    int pin;
    ServoTimer2 servoMotor;

public:
    ServoMotorImpl(const int servoMotorPin);
    void on();
    void setPosition(const int angle);
    void off();

};

#endif