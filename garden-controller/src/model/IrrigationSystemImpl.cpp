#include "IrrigationSystemImpl.h"


IrrigationSystemImpl::IrrigationSystemImpl(ServoMotor* servoMotor)
    : servo(servoMotor) {
    active = false;
}

void IrrigationSystemImpl::moveServo(const int speed) {
    static int angle = 0;
    if (angle == 180) { 
        angle = 0;
    }
    angle += speed;
    servo->setPosition(angle);
}

void IrrigationSystemImpl::irrigate(const int speed) {
    active = true;
    moveServo(speed);
}

void IrrigationSystemImpl::stop() {
    servo->setPosition(0);
    active = false;
}

bool IrrigationSystemImpl::isActive() {
    return active;
}
