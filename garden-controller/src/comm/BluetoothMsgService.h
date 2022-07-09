#ifndef __MSG_SERVICE_BT__
#define __MSG_SERVICE_BT__

#include <Arduino.h>
#include <SoftwareSerial.h>
#include "Msg.h"

/**
 * @brief The bluetooth communication service. 
 */
class BluetoothMsgService {
    
public: 
    /**
     * @brief Construct a new Bluetooth Msg Service object. 
     * @param rxPin the RX (receiver) pin
     * @param txPin the TX (sender) pin
     */
    BluetoothMsgService(int rxPin, int txPin); 

    /**
     * @brief Initialize the blueetoth service.
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
     * @brief Sends a new message through the bluetooth. 
     * @param msg the string representation of the message to send.
     */
    void sendMsg(Msg msg);

private:
    String content;
    Msg* availableMsg;
    SoftwareSerial* channel;
  
};

extern BluetoothMsgService BTMsgService;

#endif