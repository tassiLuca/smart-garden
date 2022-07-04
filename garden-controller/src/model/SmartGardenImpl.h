#ifndef __SMART_GARDEN_IMPL__
#define __SMART_GARDEN_IMPL__

#include "SmartGarden.h"

class SmartGardenImpl: public SmartGarden {

public:

    SmartGardenImpl();

    GardenState getState() override;

    LightingSystem* getLightingSystem() const override;

    IrrigationSystem* getIrrigationSystem() const override;    

private:
    LightingSystem* lightingSystem;
    IrrigationSystem* irrigationSystem;
    GardenState state;
    
};

extern SmartGardenImpl SmartGarden;

#endif