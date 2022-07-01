#ifndef __MQTT_COMM__
#define __MQTT_COMM__

#include "CommComponent.h"

class MQTTCommComponent: public CommunicationComponent {

public:
    /**
     * [NOTE] This is blocking!
     */
    void estabilishCommChannel(const char* ssid, const char* pwd) override;

};

#endif