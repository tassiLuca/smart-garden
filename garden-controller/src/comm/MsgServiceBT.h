#ifndef __MSG_SERVICE_BT__
#define __MSG_SERVICE_BT__

#include <Arduino.h>
#include <SoftwareSerial.h>
#include "Msg.h"

class MsgServiceBT {
    
public: 
    MsgServiceBT(int rxPin, int txPin);  
    void init();  
    bool isMsgAvailable();
    Msg* receiveMsg();
    void sendMsg(Msg msg);

private:
    String content;
    Msg* availableMsg;
    SoftwareSerial* channel;
  
};

extern MsgServiceBT BT;

#endif