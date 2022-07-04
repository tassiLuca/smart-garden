#include <iterator>
#include "Scheduler.h"

Scheduler::Scheduler(const int basePeriod): basePeriod(basePeriod) {
    elapsedTime = 0;
    timer.setupPeriod(basePeriod);
}

void Scheduler::addTask(Task* const task) {
    activeTasks.push_back(task);
}

void Scheduler::schedule() {
    timer.waitForNextTick();
    std::list<Task*>::iterator task;
    for (task = activeTasks.begin(); task != activeTasks.end(); task++) {
        if ((*task)->updateAndCheckTime(basePeriod)) {
            (*task)->execute();
        }
    }
}