#ifndef __IRRIGATION_ASYNC_FSM__
#define __IRRIGATION_ASYNC_FSM__

#include "../AsyncFSM.h"

class IrrigationAsyncFSM: public AsyncFSM {

public:
    IrrigationAsyncFSM();
    void handleEvent(Event* event) override;

private:
    enum {IDLE, IRRIGATING} currentState;
    void updateState(String data);
};

#endif