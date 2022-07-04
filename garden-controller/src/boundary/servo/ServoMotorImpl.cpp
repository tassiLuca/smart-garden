#include "ServoMotorImpl.h"

ServoMotorImpl::ServoMotorImpl(const int servoMotorPin)
    : pin(servoMotorPin) { }

void ServoMotorImpl::on() {
    servoMotor.attach(pin);
}

void ServoMotorImpl::off() {
    servoMotor.detach();
}

void ServoMotorImpl::setPosition(const int angle) {
    // 750 -> 0, 2250 -> 180 
    // 750 + angle*(2250-750)/180
    float coeff = (2250.0 - 750.0) / 180;
    servoMotor.write(750 + angle * coeff);
}