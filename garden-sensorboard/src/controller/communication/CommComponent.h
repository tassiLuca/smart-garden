#ifndef __COMM_COMPONENT__
#define __COMM_COMPONENT__

class CommunicationComponent {

public:
    virtual void estabilishCommChannel() = 0;
    virtual bool sendData(const char* msg) = 0;

};

#endif