#ifndef __ACTUATORS_FACTORY__
#define __ACTUATORS_FACTORY__

#include "light/Light.h"
#include "servo/ServoMotor.h"

/**
 * @brief A factory for the actuators of the system. 
 */
class ActuatorsFactory {

public:
    
    /**
     * @brief Create a new Light object.
     * @param buttonPin the pin physically attached to the light.
     * @return Light* a pointer to the new light
     */
    virtual Light* createLight(const int buttonPin) const = 0;

    /**
     * @brief Creates a new servo motor object.
     * @param servoMotorPin the pin physically attached to the servo motor.
     * @return ServoMotor* a pointer to the new servo motor.
     */
    virtual ServoMotor* createServoMotor(const int servoMotorPin) const = 0;

};

#endif