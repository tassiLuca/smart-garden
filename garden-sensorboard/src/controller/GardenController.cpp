#include <Arduino.h>
#include "GardenController.h"
#include "communication/MQTTCommComponent.h"
#include "../setup.h"

static void log(String msg) {
    Serial.println("[GARDEN CONTROLLER] " + msg);
}

GardenController::GardenController() {
    log("Init controller");
    this->comm = new MQTTCommComponent();
    this->comm->estabilishCommChannel(SSID, PWD);
}

void GardenController::run() {
    log("start running");
    // perceiveData()
    // wrapDataToJson()
    // sendData
    log("end running");
}

void GardenController::perceiveData() {

}

DynamicJsonDocument GardenController::wrapDataToJson() {

}

void GardenController::sendData() {

}
