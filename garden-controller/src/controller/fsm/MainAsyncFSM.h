#ifndef __MAIN_ASYNC_FSM__
#define __MAIN_ASYNC_FSM__

#include "../AsyncFSM.h"
#include "../serialcomm/MsgService.h"
#include "../../uilities/Logger.h"

class MainAsyncFSM: public AsyncFSM {

public:
    MainAsyncFSM();

    void handleEvent(Event* event) override;

    String getId();

};

#endif