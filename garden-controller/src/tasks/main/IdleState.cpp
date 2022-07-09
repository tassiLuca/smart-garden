#include "IdleState.h"
#include "../../comm/SerialMsgService.h"
#include "../../comm/BluetoothMsgService.h"
#include "AutoControlState.h"
#include "ManualControlState.h"

void IdleState::handle() {
    if (MsgService.isMsgAvailable() && getTask()->Garden()->getState() == AUTO) {
        this->getTask()->stateTransition(new AutoControlState());
    } else if (BTMsgService.isMsgAvailable()) {
        this->getTask()->stateTransition(new ManualControlState());
    }
    // TODO: if receive bluetooth message
}