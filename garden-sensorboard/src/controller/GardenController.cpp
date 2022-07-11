#include <Arduino.h>
#include "GardenController.h"
#include "communication/MQTTCommAgent.h"
#include "../setup.h"
#include "../uilities/Logger.h"
#include "../boundary/lightSensor/Photoresistor.h"
#include "../boundary/temperature/TemperatureSensorImpl.h"
#include "../boundary/light/Led.h"

#define MAPPED_TEMPERATURE_LEVELS 5
#define MAPPED_LIGHTNESS_LEVELS 8
#define LIGHTNESS_LEVELS 4096
#define MAX_TEMPERATURE 40

GardenController::GardenController() {
    comm = new MQTTCommAgent(SSID, PWD, MQTT_SERVER, TOPIC, MQTT_PORT);
    comm->establishCommChannel();
    temperatureSensor = new TemperatureSensorImpl(TEMPERATURE_SENSOR_PIN);
    lightSensor = new Photoresistor(PHOTORESISTOR_PIN);
    led = new Led(PIN_LED);
    led->switchOn();
}

void GardenController::run() {
    perceiveData();
    sendData(data);
}

void GardenController::perceiveData() {
    // [NOTE] By default, PubSubClient limits the message size to 256 bytes (including header)
    StaticJsonDocument<256> doc;
    doc["temperature"] = map(
        temperatureSensor->readValue(), 0, MAX_TEMPERATURE, 1, MAPPED_TEMPERATURE_LEVELS + 1
    );
    doc["lightness"] = map(
        lightSensor->readValue(), 0, LIGHTNESS_LEVELS, 1, MAPPED_LIGHTNESS_LEVELS + 1
    );
    serializeJson(doc, data);
}

void GardenController::sendData(const char* data) {
    comm->sendData(data);
}
