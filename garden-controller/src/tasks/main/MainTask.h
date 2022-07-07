#ifndef __MAIN_TASK__
#define __MAIN_TASK__

#include "../BaseTask.h"
#include "IdleState.h"

class MainTask: public BaseTask {

public:
    MainTask(const int period, SmartGarden* garden): BaseTask(period, garden) {
        this->init(new IdleState());
    }

};

#endif