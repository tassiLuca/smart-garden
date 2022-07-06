#ifndef __IRRIGATION_SYSTEM__
#define __IRRIGATION_SYSTEM__

enum OnOffState {
    ON, 
    OFF
};

class IrrigationSystem {

public:

    virtual void irrigate() = 0;

    virtual void stop() = 0;

    virtual void setIrrigationSpeed(int speed) = 0;

    virtual OnOffState getState() = 0;

    virtual void setState(OnOffState newState) = 0;

};

#endif