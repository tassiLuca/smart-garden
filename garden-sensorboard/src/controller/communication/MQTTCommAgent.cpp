#include <Arduino.h>
#include <WiFi.h>
#include "MQTTCommAgent.h"
#include "../../uilities/Logger.h"

#define CLIENT_ID_PREFIX "esiot-2122-client-"

MQTTCommAgent::MQTTCommAgent(const char* ssid, const char* pwd, 
    const char* serverAddress, const char* topic, const int port) 
    : ssid(ssid), pwd(pwd), serverAddress(serverAddress), topic(topic), port(port) { }

void MQTTCommAgent::estabilishCommChannel() {
    connectToWifi();
    connectToMQTTServer();
}

void MQTTCommAgent::connectToWifi() {
    Logger::getLogger()->log("[MQTT-AGENT] Establishing wifi-connection");
    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, pwd);
    while (WiFi.status() != WL_CONNECTED) { }
    Logger::getLogger()->log("[MQTT-AGENT] IP Address: " + WiFi.localIP().toString());
}

void MQTTCommAgent::connectToMQTTServer() {
    client.setClient(espClient);
    client.setServer(serverAddress, port);
    while (!client.connected()) {
        Logger::getLogger()->log("[MQTT-AGENT] Attempting MQTT connection...");
        String clientId = String(CLIENT_ID_PREFIX) + String(random(0xffff), HEX);
        if (client.connect(clientId.c_str())) {
            Logger::getLogger()->log("[MQTT-AGENT] MQTT connected");
        } else {
            Logger::getLogger()->log("[MQTT-AGENT] Failed, rc=" + String(client.state()));
        }
    }
}

bool MQTTCommAgent::sendData(const char* msg) {
    if (client.connected()) {
        Logger::getLogger()->log("[MQTT-AGENT] Sending data: " + String(msg) + " on " + String(topic));
        return client.publish(topic, msg);
    } else {
        return false;
    }
}
