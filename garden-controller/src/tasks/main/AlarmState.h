#ifndef __ALARM_STATE__
#define __ALARM_STATE__

#include "../Task.h"

class AlarmState: public State {

public:
    void handle() override;
    void checkTransitions() override;

};

#endif