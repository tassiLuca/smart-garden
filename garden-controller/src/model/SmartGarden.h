#ifndef __SMART_GARDEN__
#define __SMART_GARDEN__

#include "LightingSystem.h"
#include "IrrigationSystem.h"

/**
 * @brief An enum with the states of the Garden System. 
 */
enum GardenState {
    AUTO,
    MANUAL,
    ALARM
};

class SmartGarden {

public:
    /**
     * @brief Get the State of the garden. 
     * @return GardenState the current state of the garden
     */
    virtual GardenState getState() = 0;

    /**
     * @brief Set the State of the garden. 
     * @param newState the new state of the garden
     */
    virtual void setState(GardenState newState) = 0;
    
    /**
     * @brief Get the garden Lighting System.
     * @return LightingSystem* a pointer to the lighting subsystem.
     */
    virtual LightingSystem* getLightingSystem() const = 0;

    /**
     * @brief Get the garden Irrigation System.
     * @return IrrigationSystem* a pointer to the irrigation subsystem.
     */
    virtual IrrigationSystem* getIrrigationSystem() const = 0;    

};

#endif