#ifndef __MAIN_ASYNC_FSM__
#define __MAIN_ASYNC_FSM__

#include "../AsyncFSM.h"
#include "IrrigationAsyncFSM.h"
#include "LightingAsyncFSM.h"

class MainAsyncFSM: public AsyncFSM {

public:
    MainAsyncFSM();
    void handleEvent(Event* event) override;

private:
    IrrigationAsyncFSM* irrigationFSM;
    LightingAsyncFSM* lightingFSM;
    void autoHandle(String event);

};

#endif