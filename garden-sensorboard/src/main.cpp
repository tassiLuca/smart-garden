#include <Arduino.h>
#include "./controller/GardenController.h"

#define LOOP_INTERVAL 5000

unsigned long last = 0; 
MainController* controller;

void setup() {
    controller = new GardenController();
}

void loop() { 
    if (millis() - last >= LOOP_INTERVAL) {
        controller->run();
        last = millis();
    }
}