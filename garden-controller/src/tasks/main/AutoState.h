#ifndef __AUTO_STATE__
#define __AUTO_STATE__

#include "../Task.h"

class AutoState: public State {

public:
    void handle() override;

private:
    void checkTransitions(String rawData);


};

#endif