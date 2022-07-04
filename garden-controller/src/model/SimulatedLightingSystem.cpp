#include "SimulatedLightingSystem.h"
#include "../uilities/Logger.h"

void SimulatedLightingSystem::activate(const int brigtness) {
    Logger::getLogger()->log("[SIM-LS] Activating lightning system");
    active = true;
}

void SimulatedLightingSystem::deactivate() {
    Logger::getLogger()->log("[SIM-LS] Deactivated lighting system");
    active = false;
}

bool SimulatedLightingSystem::isActive() {
    return active == true;
}
