#ifndef __AUTO_CONTROL_STATE__
#define __AUTO_CONTROL_STATE__

#include "../Task.h"

class AutoControlState: public State {

public:
    void handle() override;

private:
    void setupSystem(int temperature, int lightness);

};

#endif