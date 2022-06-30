#include <Arduino.h>
#include "Led.h"

Led::Led(const int pinLed) {
    this->pin = pinLed;
    pinMode(this->pin, OUTPUT);
}

void Led::switchOff() {
    digitalWrite(this->pin, LOW);
}

void Led::switchOn() {
    digitalWrite(this->pin, HIGH);
}
