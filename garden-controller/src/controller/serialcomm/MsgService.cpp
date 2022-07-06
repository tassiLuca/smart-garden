#include "MsgService.h"
#include "../../uilities/Logger.h"

String content;

MsgServiceClass MsgService;

void MsgServiceClass::init() {
    Serial.begin(9600);
    content.reserve(256);
    content = "";
}

void MsgServiceClass::onMsgArrived(String msg) {
    this->generateEvent(new NewDataEvent(msg));
}

void serialEvent() {
    /* reading the content */
    while (Serial.available()) {
        char ch = (char) Serial.read();
        if (ch == '\n'){
            MsgService.onMsgArrived(content);
            content = "";
        } else {
            content += ch;      
        }
    }
}
