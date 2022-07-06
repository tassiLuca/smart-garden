#ifndef __IRRIGATION_SYSTEM_IMPL__
#define __IRRIGATION_SYSTEM_IMPL__

#include "IrrigationSystem.h"
#include "../boundary/servo/ServoMotor.h"

class IrrigationSystemImpl: public IrrigationSystem {

public:
    IrrigationSystemImpl(ServoMotor* servoMotor);
    void irrigate() override;
    void stop() override;
    void setIrrigationSpeed(int speed) override;
    OnOffState getState() override;
    void setState(OnOffState newState) override;

private:
    ServoMotor* servo;
    void moveServo();
    int speed;
    OnOffState state;

};

#endif