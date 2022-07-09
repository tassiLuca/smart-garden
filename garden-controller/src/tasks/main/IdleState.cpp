#include "IdleState.h"
#include "AutoState.h"
#include "ManualState.h"
#include "../../comm/SerialMsgService.h"
#include "../../comm/BluetoothMsgService.h"

void IdleState::handle() {
    if (MsgService.isMsgAvailable() && getTask()->Garden()->getState() == AUTO) {
        this->getTask()->stateTransition(new AutoState());
    } else if (BTMsgService.isMsgAvailable()) {
        this->getTask()->stateTransition(new ManualControlState());
    }
}