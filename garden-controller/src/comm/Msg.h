#ifndef __MSG__
#define __MSG__

#include <Arduino.h>

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

#endif