#include "SmartGardenImpl.h"

#include "../setup.h"
#include "../boundary/HwActuatorsFactory.h"
#include "IrrigationSystemImpl.h"
#include "LightingSystemImpl.h"
#include "../boundary/light/Light.h"
#include "../uilities/Logger.h"

SmartGardenImpl::SmartGardenImpl() {
    Logger::getLogger()->log("INIT GARDEN");
    auto factory = new HwActuatorsFactory();
    this->irrigationSystem = new IrrigationSystemImpl(factory->createServoMotor(SERVO_MOTOR_PIN));
    Light* lights[4]= {
        factory->createLight(L1_PIN), 
        factory->createLight(L2_PIN), 
        factory->createLight(L3_PIN), 
        factory->createLight(L4_PIN)
    };
    this->lightingSystem = new LightingSystemImpl(lights);
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
