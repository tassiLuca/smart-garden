#ifndef __BASE_TASK__
#define __BASE_TASK__

#include "Task.h"

class BaseTask : public Task {

private:
    const int myPeriod;
    int elapsedTime;
    bool active;
    State* currentState;

public:
    BaseTask(const int period): myPeriod(period) {
        elapsedTime = 0;
        active = false;
    }

    void init(State *state) {
        currentState = nullptr;
        stateTransition(state);
    }

    virtual void execute() {
        currentState->handle();
    };

    void stateTransition(State *nextState) {
        if (currentState != nullptr) {
            delete currentState;
        }
        currentState = nextState;
        currentState->setTask(this);
    }
    
    bool updateAndCheckTime(const int basePeriod) {
        elapsedTime += basePeriod;
        if (elapsedTime >= myPeriod) {
            elapsedTime = 0;
            return true;
        } else {
            return false;
        }
    }

    bool isActive() {
        return active;
    }

    void activate() {
        active = true;
    }

    void deactivate() {
        active = false;
    }

};

#endif