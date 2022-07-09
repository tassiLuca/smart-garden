#include "ManualState.h"
#include "SendState.h"
#include "../../comm/BluetoothMsgService.h"

void ManualState::handle() {
    Msg* msg = BTMsgService.receiveMsg();
    int index = msg->getContent().indexOf(":");
    String obj = msg->getContent().substring(0, index);
    String value = msg->getContent().substring(index+1);
    delete msg; // very important!
    if (obj == "SET-STATE" && value == "MANUAL") {
        getTask()->Garden()->setState(MANUAL);
        getTask()->Garden()->getLightingSystem()->deactivate();
    } else if (obj == "SET-STATE" && value == "AUTO") {
        getTask()->Garden()->setState(AUTO);
        getTask()->Garden()->getLightingSystem()->deactivate();
    } else if (getTask()->Garden()->getState() == MANUAL) {
        manualControl(obj, value);
    }
    getTask()->stateTransition(new SendState());
}

void ManualState::manualControl(String obj, String value) {
    if (obj == "LED1") {
        getTask()->Garden()->getLightingSystem()->setL1(value == "1" ? true : false);
    } else if (obj == "LED2") {
        getTask()->Garden()->getLightingSystem()->setL2(value == "1" ? true : false);
    } else if (obj == "LED3") {
        getTask()->Garden()->getLightingSystem()->setL3(value.toInt());
    } else if (obj == "LED4") {
        getTask()->Garden()->getLightingSystem()->setL4(value.toInt());
    } else if (obj == "IRR-SPEED") {
        getTask()->Garden()->getIrrigationSystem()->setIrrigationSpeed(value.toInt());
    } else if (obj == "IRRIGATION") {
        if (value == "1") getTask()->Garden()->getIrrigationSystem()->setState(ON);
        else getTask()->Garden()->getIrrigationSystem()->setState(OFF);        
    }
}
