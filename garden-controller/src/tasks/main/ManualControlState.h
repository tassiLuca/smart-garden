#ifndef __MANUAL_CONTROL_STATE__
#define __MANUAL_CONTROL_STATE__

#include <Arduino.h>
#include "../Task.h"

class ManualControlState: public State {

public:
    void handle() override;

private:
    void manualControl(String obj, String value);

};

#endif