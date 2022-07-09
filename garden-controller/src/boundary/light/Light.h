#ifndef __LIGHT_H__
#define __LIGHT_H__

/**
 * @brief An "interface" modeling a light. 
 */
class Light {

public:
    /**
     * @brief Switch on the light. 
     */
    virtual void switchOn() = 0;

    /**
     * @brief Switch on the light and set the 
     * intensity given in input.
     * @param intensity the intensity value
     */
    virtual void switchOn(int intensity) = 0;

    /**
     * @brief Switch off the light. 
     */
    virtual void switchOff() = 0;

};

#endif