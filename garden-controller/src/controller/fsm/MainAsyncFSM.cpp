#include "MainAsyncFSM.h"

MainAsyncFSM::MainAsyncFSM() {
    MsgService.init();
    MsgService.registerObserver(this);
}

void MainAsyncFSM::handleEvent(Event* event) {
    if (event->getType() == NEW_DATA_EVENT) {
        // check parameters in order to establish if alarm mode must be activated
        // else activate other 2 FSM
    } else {
        // change actual state
        // manual mode => 
    }
    // send over serial to the service the actual state
}

String MainAsyncFSM::getId() {
    return "MAIN-AFSM";
}
