#include <Arduino.h>
#include "OpenedState.h"
#include "ClosedState.h"

#define IRRIGATION_TIME_OUT 22000

OpenedState::OpenedState() {
    lastOpeningTime = millis();
}

void OpenedState::handle() {
    unsigned long now = millis();
    if (now - lastOpeningTime > IRRIGATION_TIME_OUT) {
        getTask()->Garden()->getIrrigationSystem()->setState(OFF);
    }
    // [NOTE] could be set off because off time out or other tasks!
    if (getTask()->Garden()->getIrrigationSystem()->getState() == OFF) {
        getTask()->Garden()->getIrrigationSystem()->stop();
        this->getTask()->stateTransition(new ClosedState());
    } else {
        getTask()->Garden()->getIrrigationSystem()->irrigate();
    }
}
