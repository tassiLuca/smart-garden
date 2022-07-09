#ifndef __SERVO_MOTOR__
#define __SERVO_MOTOR__

/**
 * @brief An "interface" modeling a servo motor. 
 */
class ServoMotor {

public:
    /**
     * @brief Turn on the motor. 
     */
    virtual void on() = 0;

    /**
     * @brief Set the Position of the servo motor.
     * @param angle an angle (expressed in degree)
     */
    virtual void setPosition(const int angle) = 0;

    /**
     * @brief Turn off the motor. 
     */
    virtual void off() = 0;

};

#endif