#ifndef __IRRIGATION_SYSTEM_IMPL__
#define __IRRIGATION_SYSTEM_IMPL__

#include "IrrigationSystem.h"
#include "../boundary/servo/ServoMotor.h"

class IrrigationSystemImpl: public IrrigationSystem {

public:
    IrrigationSystemImpl(ServoMotor* servoMotor);
    void irrigate() override;
    void setIrrigationSpeed(const int speed) override;
    bool isActive() override;
    void stop() override;

private:
    ServoMotor* servo;
    int speed;
    void moveServo();
    bool active;

};

#endif