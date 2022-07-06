#ifndef __IRRIGATION_TASK__
#define __IRRIGATION_TASK__

#include "../BaseTask.h"
#include "PauseState.h"

class IrrigationTask: public BaseTask {

public:
    IrrigationTask(const int period): BaseTask(period) {
        this->init(new PauseState());
    }

};

#endif