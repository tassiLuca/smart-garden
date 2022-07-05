#ifndef __MAIN_ASYNC_FSM__
#define __MAIN_ASYNC_FSM__

#include "../AsyncFSM.h"
#include "../serialcomm/MsgService.h"
#include "../../uilities/Logger.h"

class MainAsyncFSM: public AsyncFSM {

public:
    MainAsyncFSM();
    void handleEvent(Event* event) override;
    String getId() override;

private:
    void autoBehaviour(Event* event);
    //void alarmBehaviour(Event* event);
    //void manualBehaviour(Event* event);
    void checkTransitions(String data);
    enum {AUTO, MANUAL, ALARM} currentState;

};

#endif