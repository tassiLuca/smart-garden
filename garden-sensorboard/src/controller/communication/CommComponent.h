#ifndef __COMM_COMPONENT__
#define __COMM_COMPONENT__

class CommunicationComponent {

public:
    virtual void estabilishCommChannel(const char* ssid, const char* pwd) = 0;
    // bool sendData();

};

#endif