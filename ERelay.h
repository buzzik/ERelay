#pragma once
#include <Arduino.h>
#include <MQTTClient.h>

class ERelay {
   public:
    ERelay(byte pin = 0, String _relayName = "relay", MQTTClient* mqttObj = 0);
    boolean status;
    String relayName;
    void set(boolean val); // Установка значения для реле 
    void flip(); // Переключение значения реле на противоположное текущему

   private:
    byte _pin;
    MQTTClient* _mqttObj;

};