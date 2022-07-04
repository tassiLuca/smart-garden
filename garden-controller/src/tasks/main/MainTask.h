#ifndef __MAIN_TASK__
#define __MAIN_TASK__

#include "../BaseTask.h"
#include "AutoState.h"

class MainTask: public BaseTask {

public:
    MainTask(const int period): BaseTask(period) {
        this->init(new AutoState());
    }

};

#endif