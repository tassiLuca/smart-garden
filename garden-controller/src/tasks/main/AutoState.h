#ifndef __AUTO_STATE__
#define __AUTO_STATE__

#include "../Task.h"

class AutoState: public State {

public:
    void handle() override;
    void checkTransitions() override;

};

#endif