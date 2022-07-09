#include "IdleState.h"
#include "../../comm/MsgService.h"
#include "../../comm/MsgServiceBT.h"
#include "AutoControlState.h"
#include "ManualControlState.h"

void IdleState::handle() {
    if (MsgService.isMsgAvailable() && getTask()->Garden()->getState() == AUTO) {
        this->getTask()->stateTransition(new AutoControlState());
    } else if (BT.isMsgAvailable()) {
        this->getTask()->stateTransition(new ManualControlState());
    }
    // TODO: if receive bluetooth message
}