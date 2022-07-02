#include <Arduino.h>
#include <WiFi.h>
#include "../../uilities/Logger.h"
#include "MQTTCommComponent.h"

MQTTCommComponent::MQTTCommComponent(const char* ssid, const char* pwd, const char* serverAddress, const char* topic) {
    this->ssid = ssid;
    this->pwd = pwd;
    this->serverAddress = serverAddress;
    this->topic = topic;
}

void MQTTCommComponent::estabilishCommChannel() {
    connectToWifi();
    connectToMQTTServer();
}

void MQTTCommComponent::connectToWifi() {
    Logger::getLogger()->log("establishing wifi-connection");
    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, pwd);
    while(WiFi.status() != WL_CONNECTED) { }
    Logger::getLogger()->log("wifi-connection OK: IP Address is " + WiFi.localIP().toString());
}

void MQTTCommComponent::connectToMQTTServer() {
    client.setClient(espClient);
    client.setServer(serverAddress, 1883);
    while (!client.connected()) {
        Logger::getLogger()->log("Attempting MQTT connection...");
        String clientId = String("esiot-2122-client-")+String(random(0xffff), HEX);
        if (client.connect(clientId.c_str())) {
            Logger::getLogger()->log("MQTT connected");
        } else {
            Logger::getLogger()->log("Failed, rc=" + String(client.state()));
        }
    }
}

bool MQTTCommComponent::sendData(const char* msg) {
    if (client.connected()) {
        Logger::getLogger()->log("Sending data: " + String(msg) + " on topic " + String(topic));
        return client.publish(topic, msg);
    } else {
        return false;
    }
}
