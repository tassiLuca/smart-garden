#ifndef __OFF_STATE__
#define __OFF_STATE__

#include "../Task.h"

class OffState: public State {

public:
    OffState();
    void handle() override;

};

#endif