#ifndef __MAIN_ASYNC_FSM__
#define __MAIN_ASYNC_FSM__

#include "../AsyncFSM.h"
#include "../serialcomm/MsgService.h"
#include "../../uilities/Logger.h"

class MainAsyncFSM: public AsyncFSM {

public:
    MainAsyncFSM() {
        MsgService.init();
        MsgService.registerObserver(this);
    } 

    void handleEvent(Event* event) override {
        digitalWrite(8, HIGH);
        delay(500);
        digitalWrite(8, LOW);
    }

    String getId() {
        return "MAIN-FSM";
    }

};

#endif