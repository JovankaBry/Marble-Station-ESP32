#include <Arduino.h>
#include "BluetoothSerial.h"
#include "bluetooth.h"
#include "encoder.h"


BluetoothSerial bt;

void ble_setup(){
    bt.begin("Master", true);
}

void ble_send_1(){
    if (bt.connected()) bt.disconnect();
    bt.connect("Station1");
    delay(150);
    bt.write('R');
    Serial.println("Sending R");
    delay(100);
    bt.disconnect();
}

void ble_send_2(){
    if (bt.connected()) bt.disconnect();
    bt.connect("Station2");
    delay(150);
    bt.write('G');
    Serial.println("Sending G");
    delay(100);
    bt.disconnect();
}

void ble_send_3(){
    if (bt.connected()) bt.disconnect();
    bt.connect("Station3");
    delay(150);
    bt.write('B');
    Serial.println("Sending B");
    bt.disconnect();
}