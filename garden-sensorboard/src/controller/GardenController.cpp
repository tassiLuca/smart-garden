#include <Arduino.h>
#include "GardenController.h"
#include "communication/MQTTCommComponent.h"
#include "../setup.h"
#include "../uilities/Logger.h"

GardenController::GardenController() {
    this->comm = new MQTTCommComponent();
    this->comm->estabilishCommChannel(SSID, PWD);
}

void GardenController::run() {
    Logger::getLogger()->log("start running");
    // perceiveData()
    // wrapDataToJson()
    // sendData
    Logger::getLogger()->log("end running");
}

void GardenController::perceiveData() {

}

DynamicJsonDocument GardenController::wrapDataToJson() {

}

void GardenController::sendData() {

}
