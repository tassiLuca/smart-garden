#ifndef __SIM_IRRIGATION_SYSTEM__
#define __SIM_IRRIGATION_SYSTEM__

#include "IrrigationSystem.h"

class SimulatedIrrigationSystem: public IrrigationSystem {

public:

    void irrigate(const int speed) override;

    void setIrrigationSpeed(const int speed) override;

    bool isActive() override;

private:
    bool active;

};

#endif