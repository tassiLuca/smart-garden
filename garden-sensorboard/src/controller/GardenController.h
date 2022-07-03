#ifndef __GARDEN_CONTROLLER__
#define __GARDEN_CONTROLLER__

#include <ArduinoJson.h>
#include "MainController.h"
#include "./communication/CommComponent.h"
#include "../boundary/lightSensor/LightSensor.h"
#include "../boundary/temperature/TemperatureSensor.h"

class GardenController: public MainController {

private:
    char data[256];
    CommunicationComponent* comm;
    void perceiveData();
    void sendData(const char* data);
    LightSensor* lightSensor;
    TemperatureSensor* tempSensor;

public:
    GardenController();
    void run() override;

};

#endif