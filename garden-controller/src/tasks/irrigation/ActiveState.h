#ifndef __ACTIVE_STATE__
#define __ACTIVE_STATE__

#include "../Task.h"

class ActiveState: public State {

public:
    ActiveState();
    void handle() override;

private:
    unsigned long activationTime;

};

#endif