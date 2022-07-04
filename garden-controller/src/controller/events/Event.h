#ifndef __EVENT__
#define __EVENT__

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

class NewDataEvent: public Event { };
class ChangeStateEvent: public Event { };

#endif