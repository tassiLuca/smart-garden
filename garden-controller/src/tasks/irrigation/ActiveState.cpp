#include "ActiveState.h"
#include "PauseState.h"
#include <Arduino.h>

#define IRRIGATION_TIME 12000

void ActiveState::handle() {
    static unsigned long activationTime = millis();
    unsigned long now = millis();
    if (now - activationTime <= IRRIGATION_TIME) {
        Garden.getIrrigationSystem()->irrigate();
    } else if (now - activationTime > IRRIGATION_TIME || 
               Garden.getIrrigationSystem()->getState() == OFF) {
        Garden.getIrrigationSystem()->setState(OFF);
        Garden.getIrrigationSystem()->stop();
        this->getTask()->stateTransition(new PauseState());
    }
}