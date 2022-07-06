#ifndef __ACTIVE_STATE__
#define __ACTIVE_STATE__

#include "../Task.h"

class ActiveState: public State {

public:
    void handle() override;

};

#endif