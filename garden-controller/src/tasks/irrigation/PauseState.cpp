#include "PauseState.h"
#include "ActiveState.h"
#include "../../uilities/Logger.h"

void PauseState::handle() {
    if (getTask()->Garden()->getIrrigationSystem()->getState() == ON) {
        this->getTask()->stateTransition(new ActiveState());
    }
}