#ifndef __MANUAL_STATE__
#define __MANUAL_STATE__

#include "../Task.h"

class ManualState: public State {

public:
    void handle() override;
    void checkTransitions() override;

};

#endif