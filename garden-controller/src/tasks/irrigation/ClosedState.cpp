#include "ClosedState.h"
#include "OpenedState.h"

void ClosedState::handle() {
    if (getTask()->Garden()->getIrrigationSystem()->getState() == ON) {
        this->getTask()->stateTransition(new OpenedState());
    }
}