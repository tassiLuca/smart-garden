#include <Arduino.h>
#include "GardenController.h"
#include "communication/MQTTCommComponent.h"
#include "../setup.h"
#include "../uilities/Logger.h"
#include "../boundary/lightSensor/Photoresistor.h"
#include "../boundary/temperature/TemperatureSensorImpl.h"

#define TEMPERATURE_LEVELS 5
#define LIGHTNESS_LEVELS 8

GardenController::GardenController() {
    comm = new MQTTCommComponent(SSID, PWD, MQTT_SERVER, TOPIC);
    comm->estabilishCommChannel();
    tempSensor = new TemperatureSensorImpl(TEMPERATURE_SENSOR_PIN);
    lightSensor = new Photoresistor(PHOTORESISTOR_PIN);
}

void GardenController::run() {
    perceiveData();
    sendData(data);
}

void GardenController::perceiveData() {
    // [NOTE] By default, PubSubClient limits the message size to 256 bytes (including header)
    StaticJsonDocument<256> doc;
    JsonObject obj = doc.createNestedObject("data");
    obj["temperature"] = map(tempSensor->getValue(), 0, 43, 1, TEMPERATURE_LEVELS + 1);
    obj["lightness"] = map(lightSensor->readValue(), 0, 4096, 1, LIGHTNESS_LEVELS + 1);
    serializeJson(doc, data);
    Logger::getLogger()->log(String(data));
}

void GardenController::sendData(const char* data) {
    comm->sendData(data);
}
