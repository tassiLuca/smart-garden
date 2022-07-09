#ifndef __ON_STATE__
#define __ON_STATE__

#include "../Task.h"

class OnState: public State {

public:
    OnState();
    void handle() override;

};

#endif