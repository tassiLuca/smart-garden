#ifndef __DISPLAY_IMPL__
#define __DISPLAY_IMPL__

#include <LiquidCrystal_I2C.h>
#include "Display.h"

class DisplayImpl: public Display 
{

private:
    LiquidCrystal_I2C* lcd;
    uint8_t columns;
    uint8_t rows;
    uint8_t getDisplayAddress();

public:
    DisplayImpl(const uint8_t rows, const uint8_t columns);
    void print(const String text);
    void clear();

};

#endif