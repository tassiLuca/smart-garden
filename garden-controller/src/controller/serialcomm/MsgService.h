#ifndef __MSGSERVICE__
#define __MSGSERVICE__

#include <Arduino.h>
#include "../events/AbstractEventSource.h"
#include "../events/Event.h"

class Msg {

public:
    Msg(String content){
        this->content = content;
    }
  
    String getContent(){
        return content;
    }

private:
    String content;

};

class MsgServiceClass: public AbstractEventSource {
    
public:
    void init();
    void onMsgArrived(String msg);

};

extern MsgServiceClass MsgService;

#endif
