#ifndef __EVENT__
#define __EVENT__

/**
 * @brief Class representing an event. 
 */
class Event {

public:
    Event(const String data) : data(data) { }
    String getData() { return data; }

private:
    const String data;

};

class NewDataEvent: public Event {

public:
    NewDataEvent(const String data): Event(data) { };

};

#endif