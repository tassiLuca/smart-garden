#include <Arduino.h>
#include "./controller/GardenController.h"

MainController* controller;

void setup() {
    Serial.begin(9600);
    controller = new GardenController();
}

void loop() { 
    controller->run();
    delay(1000);
}