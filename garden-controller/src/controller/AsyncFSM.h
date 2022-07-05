#ifndef __ASYNC_FSM__
#define __ASYNC_FSM__

#include <Arduino.h>
#include <queue>
#include "Observer.h"
#include "../model/SmartGardenImpl.h"

/**
 * Base abstract class for implementing asynchronous
 * Finite State Machines.
 * NOTES
 * - it is an Observer of events generated by event source
 * - the state is meant to be modelled by derived classes
 */
class AsyncFSM: public Observer {

public:
    virtual void handleEvent(Event* event) = 0;
    void notifyEvent(Event* event);
    void checkEvents();

protected:
    AsyncFSM();
    SmartGardenImpl Garden;

private:
    std::queue<Event*> eventsQueue;

};

#endif