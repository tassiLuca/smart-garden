#include "IdleState.h"
#include "../../serialcomm/MsgService.h"
#include "AutoControlState.h"
#include "../../uilities/Logger.h"

void IdleState::handle() {
    Logger::getLogger()->log("Wait new message");
    if (MsgService.isMsgAvailable() && Garden.getState() == AUTO) {
        this->getTask()->stateTransition(new AutoControlState());
    }
    // TODO: if receive bluetooth message
}