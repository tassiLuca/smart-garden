#include <Arduino.h>

#include "controller/fsm/MainAsyncFSM.h"
#include "controller/fsm/IrrigationAsyncFSM.h"
#include "controller/fsm/LightingAsyncFSM.h"
#include "uilities/Logger.h"
#include "controller/serialcomm/MsgService.h"

SmartGarden* garden;
AsyncFSM* mainFSM;
AsyncFSM* irrigationFSM;
AsyncFSM* lightingFSM;

void setup() {
    MsgService.init();
    garden = new SmartGardenImpl();
    lightingFSM = new LightingAsyncFSM(garden);
    //irrigationFSM = new IrrigationAsyncFSM(garden);
    mainFSM = new MainAsyncFSM(garden);
    MsgService.registerObserver(mainFSM);
    MsgService.registerObserver(lightingFSM);
    Logger::getLogger()->log("INIT");
}

void loop() {
    mainFSM->checkEvents();
    //irrigationFSM->checkEvents();
    lightingFSM->checkEvents();
}
