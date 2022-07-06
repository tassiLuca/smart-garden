#ifndef __MAIN_TASK__
#define __MAIN_TASK__

#include "../BaseTask.h"
#include "IdleState.h"

class MainTask: public BaseTask {

public:
    MainTask(const int period): BaseTask(period) {
        this->init(new IdleState());
    }

};

#endif