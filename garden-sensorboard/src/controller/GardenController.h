#ifndef __GARDEN_CONTROLLER__
#define __GARDEN_CONTROLLER__

#include <ArduinoJson.h>
#include "MainController.h"
#include "./communication/CommComponent.h"

class GardenController: public MainController {

private:
    CommunicationComponent* comm;
    void perceiveData();
    DynamicJsonDocument wrapDataToJson();
    void sendData();

public:
    GardenController();
    void run() override;

};

#endif