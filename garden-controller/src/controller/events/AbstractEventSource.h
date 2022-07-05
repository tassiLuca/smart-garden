#ifndef __ABSTRACT_EVENT_SOURCE__
#define __ABSTRACT_EVENT_SOURCE__

#include <ArduinoSTL.h>
#include <list>
#include "EventSource.h"

class AbstractEventSource: public EventSource {

public:
    void registerObserver(Observer* observer) override;
    void generateEvent(Event* event) override;
    std::list<Observer*> getObservers() override;

private:
    std::list<Observer*> observers;

};

#endif