#include "AbstractEventSource.h"

void AbstractEventSource::registerObserver(Observer* observer) {
    observers.push_back(observer);
}

void AbstractEventSource::generateEvent(Event* event) {
    std::list<Observer*>::iterator ob;
    for (ob = observers.begin(); ob != observers.end(); ob++) {
        (*ob)->notifyEvent(event);
    }
}

std::list<Observer*> AbstractEventSource::getObservers() {
    return observers;
}
