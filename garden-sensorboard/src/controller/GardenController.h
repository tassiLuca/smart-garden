#ifndef __GARDEN_CONTROLLER__
#define __GARDEN_CONTROLLER__

#include <ArduinoJson.h>
#include "MainController.h"
#include "./communication/CommAgent.h"
#include "../boundary/lightSensor/LightSensor.h"
#include "../boundary/temperature/TemperatureSensor.h"

class GardenController: public MainController {

public:
    GardenController();
    void run() override;

private:
    char data[256];
    CommAgent* comm;
    void perceiveData();
    void sendData(const char* data);
    LightSensor* lightSensor;
    TemperatureSensor* temperatureSensor;

};

#endif