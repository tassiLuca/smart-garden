#include <Arduino.h>
#include "MsgService.h"

String content;

MsgServiceClass MsgService;

void MsgServiceClass::init() {
    Serial.begin(9600);
    content.reserve(256);
    content = "";
}

void MsgServiceClass::onMsgArrived(String msg) {
    //digitalWrite(7, HIGH);
    this->generateEvent(new NewDataEvent());
    //delay(500);
    //digitalWrite(7, LOW);
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
