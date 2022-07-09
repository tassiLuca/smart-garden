#include "PauseState.h"
#include "ActiveState.h"

void PauseState::handle() {
    if (getTask()->Garden()->getIrrigationSystem()->getState() == ON) {
        this->getTask()->stateTransition(new ActiveState());
    }
}