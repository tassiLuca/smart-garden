#include <Arduino.h>
#include "./setup.h"
#include "./boundary/light/Led.h"
#include "./test.h"

Light* led;
Test test;

void testBoundary();

void setup() {
    Serial.begin(9600);
    led = new Led(PIN_LED);
}

void loop() {
    test.testLed(led);
}