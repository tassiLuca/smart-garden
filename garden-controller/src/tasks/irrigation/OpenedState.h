#ifndef __ACTIVE_STATE__
#define __ACTIVE_STATE__

#include "../Task.h"

class OpenedState: public State {

public:
    OpenedState();
    void handle() override;

private:
    unsigned long lastOpeningTime;

};

#endif