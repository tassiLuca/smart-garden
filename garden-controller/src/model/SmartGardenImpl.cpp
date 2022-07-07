#include "SmartGardenImpl.h"
#include "../boundary/HwActuatorsFactory.h"
#include "IrrigationSystemImpl.h"
#include "LightingSystemImpl.h"
#include "../setup.h"

SmartGardenImpl::SmartGardenImpl() {
    auto factory = new HwActuatorsFactory();
    this->irrigationSystem = new IrrigationSystemImpl(factory->createServoMotor(SERVO_MOTOR_PIN));
    Light* l1 = factory->createLight(L1_PIN);
    Light* l2 = factory->createLight(L2_PIN);
    Light* l3 = factory->createLight(L3_PIN); 
    Light* l4 = factory->createLight(L4_PIN);
    this->lightingSystem = new LightingSystemImpl(l1, l2, l3, l4);
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

void SmartGardenImpl::setState(GardenState newState) {
    this->state = newState;
}
