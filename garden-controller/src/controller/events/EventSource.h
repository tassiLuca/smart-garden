#ifndef __EVENT_SOURCE__
#define __EVENT_SOURCE__

#include "../Observer.h"

/**
 * @brief Base class representing an event source, generating
 * Events observed by an Observer. 
 */
class EventSource {

public:
    virtual void registerObserver(Observer* observer) = 0;
    virtual void generateEvent(Event* event) = 0;

};

#endif