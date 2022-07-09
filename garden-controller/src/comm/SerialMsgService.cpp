#include "Arduino.h"
#include "SerialMsgService.h"

static String content;
SerialMsgService MsgService;

bool SerialMsgService::isMsgAvailable() {
    return msgAvailable;
}

Msg* SerialMsgService::receiveMsg() {
    if (msgAvailable) {
        Msg* msg = currentMsg;
        msgAvailable = false;
        currentMsg = NULL;
        content = "";
        return msg;  
    } else {
        return NULL; 
    }
}

void SerialMsgService::init() {
    Serial.begin(9600);
    content.reserve(256);
    content = "";
    currentMsg = NULL;
    msgAvailable = false;  
}

void SerialMsgService::sendMsg(const String& msg) {
    Serial.println(msg);  
}

/**
 * @brief This is the Arduino interrupt callback of a new serial event. 
 */
void serialEvent() {
    while (Serial.available()) {
        char ch = (char) Serial.read();
        if (ch == '\n'){
            MsgService.currentMsg = new Msg(content);
            MsgService.msgAvailable = true;      
        } else {
            content += ch;      
        }
    }
}
