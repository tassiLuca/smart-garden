#include "IrrigationSystemImpl.h"
#include "../uilities/Logger.h"

#define DEFAULT_SPEED 2

IrrigationSystemImpl::IrrigationSystemImpl(ServoMotor* servoMotor)
    : servo(servoMotor) {
    speed = DEFAULT_SPEED;
    active = false;
}

void IrrigationSystemImpl::moveServo() {
    static int angle = 0;
    if (angle == 180) { 
        angle = 0;
    }
    angle += speed;
    servo->setPosition(angle);
}

void IrrigationSystemImpl::irrigate() {
    active = true;
    moveServo();
}

bool IrrigationSystemImpl::isActive() {
    return active;
}

void IrrigationSystemImpl::setIrrigationSpeed(const int speed) {
    this->speed = speed;
}

void IrrigationSystemImpl::stop() {
    servo->setPosition(0);
    active = false;
}
