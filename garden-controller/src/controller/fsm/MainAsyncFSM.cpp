#include "MainAsyncFSM.h"

MainAsyncFSM::MainAsyncFSM() {
    MsgService.init();
    MsgService.registerObserver(this);
}

void MainAsyncFSM::handleEvent(Event* event) {
    digitalWrite(8, HIGH);
    delay(500);
    digitalWrite(8, LOW);
}

String MainAsyncFSM::getId() {
    return "MAIN-AFSM";
}