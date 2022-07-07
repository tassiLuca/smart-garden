#include "SendDataState.h"
#include "../../serialcomm/MsgService.h"
#include "IdleState.h"

void SendDataState::handle() {
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
    getTask()->stateTransition(new IdleState());
}
