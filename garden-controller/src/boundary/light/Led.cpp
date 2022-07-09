#include <Arduino.h>
#include "Led.h"

#define MIN_ADC_VALUE 0
#define MAX_ADC_VALUE 255

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

void Led::switchOn(int intensity) {
    if (intensity <= MAX_ADC_VALUE && intensity >= MIN_ADC_VALUE) {
        analogWrite(this->pin, intensity);
    }
}
