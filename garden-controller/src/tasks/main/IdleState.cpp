#include "IdleState.h"
#include "../../comm/MsgService.h"
#include "AutoControlState.h"
#include "../../uilities/Logger.h"

void IdleState::handle() {
    Logger::getLogger()->log("Wait new message");
    if (MsgService.isMsgAvailable() && getTask()->Garden()->getState() == AUTO) {
        this->getTask()->stateTransition(new AutoControlState());
    }
    // TODO: if receive bluetooth message
}