#ifndef __LIGHTING_ASYNC_FSM__
#define __LIGHTING_ASYNC_FSM__

#include "../AsyncFSM.h"

class LightingAsyncFSM: public AsyncFSM {

public:
    LightingAsyncFSM();
    void handleEvent(Event* event) override;

private:
    enum {IDLE, ACTIVE} currentState;
    int getLightness(String data);
    void updateState(int lightnessLevel);

};

#endif