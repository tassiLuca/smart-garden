#ifndef __IRRIGATION_SYSTEM__
#define __IRRIGATION_SYSTEM__

class IrrigationSystem {

public:

    virtual void irrigate(const int speed) = 0;

    virtual void stop() = 0;

    virtual bool isActive() = 0;

};

#endif