#include <Arduino.h>
#include "Logger.h"
#include "../boundary/display/DisplayImpl.h"
#include "../setup.h"

Logger* Logger::logger = nullptr;

Logger::Logger() {
    display = new DisplayImpl(DISPLAY_ROWS, DISPLAY_COLS);
}

Logger* Logger::getLogger() {
    if (logger == nullptr) {
        logger = new Logger();
        Serial.begin(9600);
    }
    return logger;
}

void Logger::log(const String msg) {
    display->clear();
    display->print(msg);
}
