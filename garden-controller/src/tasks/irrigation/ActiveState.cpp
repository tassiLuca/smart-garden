#include "ActiveState.h"
#include "PauseState.h"
#include <Arduino.h>

#define IRRIGATION_TIME 22000

ActiveState::ActiveState() {
    activationTime = millis();
}

void ActiveState::handle() {
    unsigned long now = millis();
    if (now - activationTime > IRRIGATION_TIME || 
        getTask()->Garden()->getIrrigationSystem()->getState() == OFF) {
        getTask()->Garden()->getIrrigationSystem()->setState(OFF);
        getTask()->Garden()->getIrrigationSystem()->stop();
        this->getTask()->stateTransition(new PauseState());
    } else {
        getTask()->Garden()->getIrrigationSystem()->irrigate();
    }
}