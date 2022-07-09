#ifndef __PAUSE_STATE__
#define __PAUSE_STATE__

#include "../Task.h"

class ClosedState: public State {

public:
    void handle() override;

};

#endif