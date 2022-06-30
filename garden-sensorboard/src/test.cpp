#include "test.h"
#include <Arduino.h>

void Test::testLed(Light* led) {
    Serial.println("Switching on led");
    led->switchOn();
    delay(1000);
    Serial.println("Switching off led");
    led->switchOff();
    delay(1000);
}
