#ifndef __EVENT__
#define __EVENT__

#define NEW_DATA_EVENT 0
#define CHANGE_STATE_EVENT 1

/**
 * @brief Class representing an event. 
 */
class Event {

public:
    Event(const int type) : type(type) {}
    int getType() { return type; }

private:
    int type;

};

class NewDataEvent: public Event {

public:
    NewDataEvent(): Event(NEW_DATA_EVENT) { };

};


class ChangeStateEvent: public Event { 

public:
    ChangeStateEvent(): Event(CHANGE_STATE_EVENT) { };

};

#endif