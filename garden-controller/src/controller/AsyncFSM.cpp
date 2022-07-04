#include "AsyncFSM.h"
#include <Arduino.h>

AsyncFSM::AsyncFSM() {}

void AsyncFSM::notifyEvent(Event* event) {
    eventsQueue.push(event);
}

void AsyncFSM::checkEvents() {
    noInterrupts();
    bool isEmpty = eventsQueue.empty();
    interrupts();
    if (!isEmpty) {
        noInterrupts();
        Event* event = eventsQueue.front();
        eventsQueue.pop();
        interrupts();
        if (event != NULL) {
            handleEvent(event);
            delete event;
        }
    }
}
