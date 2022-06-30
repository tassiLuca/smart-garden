#include <Arduino.h>
#include "Photoresistor.h"

Photoresistor::Photoresistor(const int photoresistorPin) {
    this->pin = photoresistorPin;
}