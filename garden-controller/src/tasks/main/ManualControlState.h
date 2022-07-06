#ifndef __MANUAL_CONTROL_STATE__
#define __MANUAL_CONTROL_STATE__

#include "../Task.h"

class ManualControlState: public State {

public:
    void handle() override;

};

#endif