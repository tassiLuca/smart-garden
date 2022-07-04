#include "AutoState.h"
#include "../../uilities/Logger.h"
#include "../../serialcomm/MsgService.h"

void AutoState::handle() {
    Logger::getLogger()->log("AUTO STATE");
    if (MsgService.isMsgAvailable()) {
        Msg* msg = MsgService.receiveMsg();
        Logger::getLogger()->log("New message " + msg->getContent());
        delete msg;
    }


    // se è stato ricevuto un nuovo messaggio
    //      verifica se condizioni di allarme o manual mode
    //      se **non** condizione di allarme
    //          attiva gli altri due task
}
