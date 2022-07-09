#ifndef __SERIAL_MSG_SERVICE__
#define __SERIAL_MSG_SERVICE__

#include <Arduino.h>
#include "Msg.h"

/**
 * @brief The serial communication service. 
 */
class SerialMsgService {

public: 
    /** The current message. */
    Msg* currentMsg;
    /** A boolean property for msg availability check. */
    bool msgAvailable;
    
    /**
     * @brief Initialize the serial service. 
     */
    void init();  

    /**
     * @brief Returns true if the message is available, false otherwise. 
     * @return true if an available message has not been 
     * already consumed, false otherwise.
     */
    bool isMsgAvailable();

    /**
     * @brief Returns the last message received.
     * @return Msg* a pointer to the last message.
     * @note The message deallocation is responsability of the client!
     */
    Msg* receiveMsg();
  
    /**
     * @brief Sends a new message through the serial line. 
     * @param msg the string representation of the message to send.
     */
    void sendMsg(const String& msg);
};

extern SerialMsgService MsgService;

#endif
