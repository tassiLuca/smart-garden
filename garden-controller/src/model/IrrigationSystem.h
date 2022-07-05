#ifndef __IRRIGATION_SYSTEM__
#define __IRRIGATION_SYSTEM__

class IrrigationSystem {

public:

    virtual void irrigate(const int speed) = 0;

    virtual void setIrrigationSpeed(const int speed) = 0;

};

#endif