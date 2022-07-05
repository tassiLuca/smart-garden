#ifndef __SMART_GARDEN__
#define __SMART_GARDEN__

#include "LightingSystem.h"
#include "IrrigationSystem.h"

enum GardenState {
    AUTO,
    MANUAL,
    ALARM
};

class SmartGarden {

public:

    virtual GardenState getState() = 0;

    virtual LightingSystem* getLightingSystem() const = 0;

    virtual IrrigationSystem* getIrrigationSystem() const = 0;    

};

#endif