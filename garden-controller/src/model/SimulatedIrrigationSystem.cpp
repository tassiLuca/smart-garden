#include "SimulatedIrrigationSystem.h"
#include "../uilities/Logger.h"

void SimulatedIrrigationSystem::irrigate(const int speed) {
    static int angle = 0;
    if (angle == 180) {
        angle = 0;
        active = false;
        Logger::getLogger()->log("[SIM-IS] End irrigation");
    } else {
        angle += speed;
        active = true;
        Logger::getLogger()->log("[SIM-IS] Irrigating");
    }
}

void SimulatedIrrigationSystem::setIrrigationSpeed(const int speed) {
    Logger::getLogger()->log("[SIM-IS] Speed: " + String(speed));
}

bool SimulatedIrrigationSystem::isActive() {
    return active;
}
