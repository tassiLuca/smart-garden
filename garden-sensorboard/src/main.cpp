#include <Arduino.h>
#include "./controller/GardenController.h"

MainController* controller;

void setup() {
    controller = new GardenController();
}

void loop() { 
    controller->run();
    delay(5000);
}