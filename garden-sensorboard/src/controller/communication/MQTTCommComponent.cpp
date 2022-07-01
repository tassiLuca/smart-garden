#include <Arduino.h>
#include <WiFi.h>
#include "MQTTCommComponent.h"

static void log(String msg) {
    Serial.println("[MQTT] " + msg);
}

bool MQTTCommComponent::estabilishCommChannel(const char* ssid, const char* pwd) {
    log("Estabilishing a connection");
    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, pwd);
    while(WiFi.status() != WL_CONNECTED) {
        log("nope");
    }
    log("established");
    return false;
}