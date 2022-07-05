#include <Arduino.h>

#include "controller/fsm/MainAsyncFSM.h"

AsyncFSM* mainFSM;

void setup() {
    mainFSM = new MainAsyncFSM();
}

void loop() {
    mainFSM->checkEvents();
}
