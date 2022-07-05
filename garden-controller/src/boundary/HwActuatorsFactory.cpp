#include "HwActuatorsFactory.h"

#include "../boundary/light/Led.h"
#include "../boundary/servo/ServoMotorImpl.h"

Light* HwActuatorsFactory::createLight(const int lightPin) const {
    return new Led(lightPin);
}

ServoMotor* HwActuatorsFactory::createServoMotor(const int servoMotorPin) const {
    auto servo = new ServoMotorImpl(servoMotorPin);
    servo->on();
    return servo;
}
