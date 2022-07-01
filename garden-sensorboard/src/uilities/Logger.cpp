#include <Arduino.h>
#include "Logger.h"

Logger* Logger::logger = nullptr;

Logger* Logger::getLogger() {
    if (logger == nullptr) {
        logger = new Logger();
        Serial.begin(9600);
    }
    return logger;
}

void Logger::log(const String msg) {
    Serial.println(msg);
}
