#ifndef __OBSERVER__
#define __OBSERVER__

#include <Arduino.h>
#include "events/Event.h"

/**
 * @brief Class representing event observers, observing Events. 
 */
class Observer {

public:
    virtual void notifyEvent(Event* event) = 0;

};

#endif