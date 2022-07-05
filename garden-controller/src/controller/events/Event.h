#ifndef __EVENT__
#define __EVENT__

#define NEW_DATA_EVENT 0
#define CHANGE_STATE_EVENT 1

/**
 * @brief Class representing an event. 
 */
class Event {

public:
    Event(const int type, const String data) : type(type), data(data) {}
    int getType() { return type; }
    String getData() { return data; }

private:
    int type;
    String data;

};

class NewDataEvent: public Event {

public:
    NewDataEvent(const String data): Event(NEW_DATA_EVENT, data) { };

};


class ChangeStateEvent: public Event { 

public:
    ChangeStateEvent(const String data): Event(CHANGE_STATE_EVENT, data) { };

};

#endif