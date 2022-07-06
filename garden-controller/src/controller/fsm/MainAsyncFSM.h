#ifndef __MAIN_ASYNC_FSM__
#define __MAIN_ASYNC_FSM__

#include "../AsyncFSM.h"
#include "IrrigationAsyncFSM.h"
#include "LightingAsyncFSM.h"

class MainAsyncFSM: public AsyncFSM {

public:
    MainAsyncFSM(SmartGarden* garden);
    void handleEvent(Event* event) override;

};

#endif