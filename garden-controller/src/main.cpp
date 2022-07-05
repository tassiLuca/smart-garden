#include <Arduino.h>

#include "controller/fsm/MainAsyncFSM.h"
#include "controller/fsm/IrrigationAsyncFSM.h"
#include "controller/fsm/LightingAsyncFSM.h"

AsyncFSM* mainFSM;
AsyncFSM* irrigationFSM;
AsyncFSM* lightingFSM;

void setup() {
    irrigationFSM = new IrrigationAsyncFSM();
    lightingFSM = new LightingAsyncFSM();
    mainFSM = new MainAsyncFSM();
}

void loop() {
    mainFSM->checkEvents();
    irrigationFSM->checkEvents();
    lightingFSM->checkEvents();
}
