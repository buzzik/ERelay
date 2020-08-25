#include "ERelay.h"

#include <Arduino.h>
#include <MQTTClient.h>

//Constructor
ERelay::ERelay(byte pin, String _relayName, MQTTClient* mqttObj) {
    _pin = pin;
    relayName = _relayName;
    pinMode(_pin, OUTPUT);
    _mqttObj = mqttObj;
}
void ERelay::set(boolean val) {
    if (status != val) {
        digitalWrite(_pin, val);
        status = val;
        Serial.println(relayName + " recieved command - " + val);
        if (_mqttObj != 0) {
            if (val == HIGH || val == 1) {
                _mqttObj->publish("/" + relayName + "/state", "1");
            } else {
                _mqttObj->publish("/" + relayName + "/state", "0");
            }
        }
    }
}
void ERelay::flip() {
    if (status == HIGH) {
        set(LOW);
    } else {
        set(HIGH);
    }
}
