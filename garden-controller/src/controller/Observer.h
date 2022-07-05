#ifndef __OBSERVER__
#define __OBSERVER__

#include "events/Event.h"

/**
 * @brief Class representing event observers, observing Events. 
 */
class Observer {

public:
    virtual void notifyEvent(Event* event) = 0;
    virtual String getId() = 0;

};

#endif