#ifndef __IRRIGATION_TASK__
#define __IRRIGATION_TASK__

#include "../BaseTask.h"
#include "ClosedState.h"

/**
 * @brief Task with the responsability to manage
 * the opening/closing of the irrigation system. 
 */
class IrrigationTask: public BaseTask {

public:
    IrrigationTask(const int period, SmartGarden* garden): BaseTask(period, garden) {
        this->init(new ClosedState());
    }

};

#endif