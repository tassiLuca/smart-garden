#ifndef __MANUAL_STATE__
#define __MANUAL_STATE__

#include <Arduino.h>
#include "../Task.h"

class ManualState: public State {

public:
    void handle() override;

private:
    void manualControl(String obj, String value);

};

#endif