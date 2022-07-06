#ifndef __IRRIGATION_SYSTEM_IMPL__
#define __IRRIGATION_SYSTEM_IMPL__

#include "IrrigationSystem.h"
#include "../boundary/servo/ServoMotor.h"

class IrrigationSystemImpl: public IrrigationSystem {

public:
    IrrigationSystemImpl(ServoMotor* servoMotor);
    void irrigate(const int speed) override;
    void stop() override;
    bool isActive() override;

private:
    ServoMotor* servo;
    void moveServo(const int speed);
    bool active;

};

#endif