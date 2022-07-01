#include <Arduino.h>
#include "GardenController.h"
#include "communication/MQTTCommComponent.h"
#include "../setup.h"
#include "../uilities/Logger.h"

GardenController::GardenController() {
    this->comm = new MQTTCommComponent(SSID, PWD, MQTT_SERVER, TOPIC);
    this->comm->estabilishCommChannel();
}

void GardenController::run() {
    this->comm->sendData("hello world smart-garden");
}

void GardenController::perceiveData() {
    // TODO
}

void GardenController::sendData() {
    // TODO
}
