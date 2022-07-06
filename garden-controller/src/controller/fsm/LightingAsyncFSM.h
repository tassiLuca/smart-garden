#ifndef __LIGHTING_ASYNC_FSM__
#define __LIGHTING_ASYNC_FSM__

#include "../AsyncFSM.h"

class LightingAsyncFSM: public AsyncFSM {

public:
    LightingAsyncFSM(SmartGarden* garden);
    void handleEvent(Event* event) override;

};

#endif