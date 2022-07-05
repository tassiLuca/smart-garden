#include "IrrigationAsyncFSM.h"
#include <ArduinoJson.h>
#include "../serialcomm/MsgService.h"
#include "../../uilities/Logger.h"

IrrigationAsyncFSM::IrrigationAsyncFSM() {
    currentState = IDLE;
    MsgService.registerObserver(this);
}

void IrrigationAsyncFSM::handleEvent(Event* event) {
    if (Garden.getState() != ALARM) {
        
    }
}

void IrrigationAsyncFSM::updateState(String data) {

}
