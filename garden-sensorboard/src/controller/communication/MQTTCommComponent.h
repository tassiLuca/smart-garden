#ifndef __MQTT_COMM__
#define __MQTT_COMM__

#include <WiFi.h>
#include <PubSubClient.h>
#include "CommComponent.h"

class MQTTCommComponent: public CommunicationComponent {

public:
    MQTTCommComponent(const char* ssid, const char* pwd, const char* serverAddress, const char* topic);

    /**
     * [NOTE] This is blocking!
     */
    void estabilishCommChannel() override;
    bool sendData(const char* msg) override;

private:
    WiFiClient espClient;
    PubSubClient client;
    const char* ssid;
    const char* pwd;
    const char* serverAddress;
    const char* topic;
    void connectToWifi();
    void connectToMQTTServer();

};

#endif