#include "SimulatedIrrigationSystem.h"
#include "../uilities/Logger.h"

void SimulatedIrrigationSystem::irrigate(const int speed) {
    Logger::getLogger()->log("[SIM-IS] Irrigating");
}

void SimulatedIrrigationSystem::setIrrigationSpeed(const int speed) {
    Logger::getLogger()->log("[SIM-IS] Speed: " + String(speed));
}
