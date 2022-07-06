#ifndef __IDLE_STATE__
#define __IDLE_STATE__

#include "../Task.h"

class IdleState: public State {

public:
    void handle() override;

};

#endif