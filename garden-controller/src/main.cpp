#include <Arduino.h>

#include "model/SmartGardenImpl.h"
#include "controller/fsm/MainAsyncFSM.h"
#include "setup.h"

SmartGarden* garden;
AsyncFSM* mainFSM;

void setup() {
    garden = new SmartGardenImpl();
    mainFSM = new MainAsyncFSM();
}

void loop() {
    mainFSM->checkEvents();
}
