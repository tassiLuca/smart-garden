#ifndef __IRRIGATION_ASYNC_FSM__
#define __IRRIGATION_ASYNC_FSM__

#include "../AsyncFSM.h"

class IrrigationAsyncFSM: public AsyncFSM {

public:
    IrrigationAsyncFSM(SmartGarden* garden);
    void handleEvent(Event* event) override;

};

#endif