#include "SendState.h"
#include "../../comm/SerialMsgService.h"
#include "../../comm/BluetoothMsgService.h"
#include "IdleState.h"

void SendState::handle() {
    String currentStateDescription;
    auto currentState = getTask()->Garden()->getState();
    switch (currentState) {
        case AUTO:
            currentStateDescription = "AUTO";
            break;
        case MANUAL:
            currentStateDescription = "MANUAL";
            break;
        case ALARM:
            currentStateDescription = "ALARM";
            break;
        default:
            break;
    }
    MsgService.sendMsg(currentStateDescription);
    BTMsgService.sendMsg(currentStateDescription);
    getTask()->stateTransition(new IdleState());
}
