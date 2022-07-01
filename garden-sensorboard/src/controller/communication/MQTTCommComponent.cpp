#include <Arduino.h>
#include <WiFi.h>
#include "../../uilities/Logger.h"
#include "MQTTCommComponent.h"

void MQTTCommComponent::estabilishCommChannel(const char* ssid, const char* pwd, const char* serverAddress) {
    Logger::getLogger()->log("establishing wifi-connection");
    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, pwd);
    while(WiFi.status() != WL_CONNECTED) { }
    Logger::getLogger()->log("wifi-connection OK: IP Address is " + WiFi.localIP().toString());
    WiFiClient espClient;

    client.setClient(espClient);
    client.setServer(serverAddress, 1883);
    
    while (!client.connected()) {
        Logger::getLogger()->log("Attempting MQTT connection...");
        String clientId = String("esiot-2122-client-")+String(random(0xffff), HEX);
        // Attempt to connect
        if (client.connect(clientId.c_str())) {
            Logger::getLogger()->log("MQTT connected...");
        } else {
            Logger::getLogger()->log("Failed, rc=" + String(client.state()));
            // Wait 5 seconds before retrying
            delay(5000);
        }
    }
}

