#ifndef __SCHEDULER__
#define __SCHEDULER__

#include <SchedulerTimer.h>
#include <ArduinoSTL.h>
#include <list>
#include "../tasks/Task.h"

/**
 * @brief A class modeling a scheduler.
 */
class Scheduler {

private:
    int basePeriod;
    int elapsedTime;
    std::list<Task*> activeTasks;
    SchedulerTimer timer;

public:
    /**
     * @brief Construct a new Scheduler object
     * @param basePeriod the period, measured in ms.
     * The period must be equals to the greatest common 
     * divisor among the period of the tasks.
     */
    Scheduler(const int basePeriod);

    /**
     * @brief Add a task to the current active task bunch.
     * @param task a pointer to the task to add.
     */
    void addTask(Task* const task);

    /**
     * @brief Routine which, every basePeriod, executes each
     * task, according to its behaviour. 
     */
    void schedule();

};

#endif