#ifndef __MQTT_COMM__
#define __MQTT_COMM__

#include <PubSubClient.h>
#include "CommComponent.h"

class MQTTCommComponent: public CommunicationComponent {

public:
    /**
     * [NOTE] This is blocking!
     */
    void estabilishCommChannel(const char* ssid, const char* pwd, const char* serverAddress) override;

private:
    PubSubClient client;

};

#endif