#include <Arduino.h>
#include "TemperatureSensorImpl.h"

// Power supply in mV
#define POWER_SUPPLY 3300
// The max value for analog read
#define MAX_INPUT_VALUE 4096.0

TemperatureSensorImpl::TemperatureSensorImpl(const int temperatureSensorPin) {
    this->pin = temperatureSensorPin;
}

float TemperatureSensorImpl::getValue() {
    float mVValue = analogRead(pin) * (POWER_SUPPLY / MAX_INPUT_VALUE);
    return mVValue * 0.1;
}
