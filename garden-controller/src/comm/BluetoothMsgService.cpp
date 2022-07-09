#include "BluetoothMsgService.h"
#include "../setup.h"

BluetoothMsgService BTMsgService(BT_ARDUINO_RX, BT_ARDUINO_TX);

BluetoothMsgService::BluetoothMsgService(int rxPin, int txPin){
    channel = new SoftwareSerial(rxPin, txPin);
}

void BluetoothMsgService::init(){
    content.reserve(256);
    channel->begin(9600);
    availableMsg = NULL;
}

void BluetoothMsgService::sendMsg(Msg msg){
    channel->println(msg.getContent());  
}

bool BluetoothMsgService::isMsgAvailable(){
    while (channel->available()) {
        char ch = (char) channel->read();
        if (ch == '\n'){
            availableMsg = new Msg(content); 
            content = "";
            return true;    
        } else {
            content += ch;      
        }
    }
    return false;  
}

Msg* BluetoothMsgService::receiveMsg(){
    if (availableMsg != NULL){
        Msg* msg = availableMsg;
        availableMsg = NULL;
        return msg;  
    } else {
        return NULL;
    }
}
