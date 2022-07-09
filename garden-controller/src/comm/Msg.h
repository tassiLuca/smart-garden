#ifndef __MSG__
#define __MSG__

#include <Arduino.h>

/**
 * @brief A simple class modeling the concept of a message. 
 */
class Msg {

public:
    Msg(String content){
        this->content = content;
    }
  
    /**
     * @brief Get the string representation of the message. 
     * @return String the message
     */
    String getContent(){
        return content;
    }

private:
    String content;

};

#endif