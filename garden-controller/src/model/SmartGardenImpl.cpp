#include "SmartGardenImpl.h"
#include "SimulatedIrrigationSystem.h"
#include "SimulatedLightingSystem.h"

SmartGardenImpl::SmartGardenImpl() {
    this->irrigationSystem = new SimulatedIrrigationSystem();
    this->lightingSystem = new SimulatedLightingSystem();
    this->state = GardenState::AUTO;
}

IrrigationSystem* SmartGardenImpl::getIrrigationSystem() const {
    return this->irrigationSystem;
}

LightingSystem* SmartGardenImpl::getLightingSystem() const {
    return this->lightingSystem;
}

GardenState SmartGardenImpl::getState() {
    return this->state;
}
