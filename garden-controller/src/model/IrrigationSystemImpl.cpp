#include "IrrigationSystemImpl.h"

#define DEFAULT_SPEED = 1;

IrrigationSystemImpl::IrrigationSystemImpl(ServoMotor* servoMotor): servo(servoMotor) { 
    state = OFF;
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
    moveServo();
}

void IrrigationSystemImpl::stop() {
    servo->setPosition(0);
}

void IrrigationSystemImpl::setIrrigationSpeed(int speed) {
    this->speed = speed;
}

OnOffState IrrigationSystemImpl::getState() {
    return state;
}

void IrrigationSystemImpl::setState(OnOffState newState) {
    state = newState;
}
