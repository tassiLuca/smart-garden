#ifndef __LIGHTING_TASK__
#define __LIGHTING_TASK__

#include "../BaseTask.h"
#include "OffState.h"

/**
 * @brief Task with the responsability to manage
 * the lighting system.
 */
class LightingTask: public BaseTask {

public:
    LightingTask(const int period, SmartGarden* garden): BaseTask(period, garden) {
        this->init(new OffState());
    }

};

#endif