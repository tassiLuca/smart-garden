#ifndef __MSGSERVICE__
#define __MSGSERVICE__

#include <Arduino.h>
#include "Msg.h"

class MsgServiceClass {
    
public: 
    Msg* currentMsg;
    bool msgAvailable;

    void init();  

    bool isMsgAvailable();
    /* note: message deallocation is responsibility of the client */
    Msg* receiveMsg();
  
    void sendMsg(const String& msg);
};

extern MsgServiceClass MsgService;

#endif
