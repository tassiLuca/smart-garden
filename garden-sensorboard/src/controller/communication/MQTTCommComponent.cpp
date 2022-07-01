#include <Arduino.h>
#include <WiFi.h>
#include "../../uilities/Logger.h"
#include "MQTTCommComponent.h"

static void log(String msg) {
    Serial.println("[MQTT] " + msg);
}

void MQTTCommComponent::estabilishCommChannel(const char* ssid, const char* pwd) {
    Logger::getLogger()->log("establishing wifi-connection");
    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, pwd);
    while(WiFi.status() != WL_CONNECTED) { }

    Logger::getLogger()->log("wifi-connection OK: IP Address is " + WiFi.localIP().toString());
}

