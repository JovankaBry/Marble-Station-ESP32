#include <Arduino.h>
#include "BluetoothSerial.h"
#include "bluetooth.h"

BluetoothSerial bt;

void ble_setup(){
    bt.begin("Master", true);
    bt.connect("Slave");
    delay(300);
}

void ble_send_1(){
    if(!bt.connected()){
        Serial.println("Connecting...");
        bt.connect("Slave");
        delay(300);
        return;
    }

    if (bt.connected()){
        bt.write('1');
        Serial.println("Sent 1");
    } else {
        Serial.println("Failed to connect");
    }
}

void ble_send_2(){
    if(!bt.connected()){
        Serial.println("Connecting...");
        bt.connect("Slave");
        delay(300);
        return;
    }

    if (bt.connected()){
        bt.write('2');
        Serial.println("Sent 2");
    } else {
        Serial.println("Failed to connect");
    }

}

void ble_send_3(){
    if (!bt.connected()){
        Serial.println("Connecting...");
        bt.connect("Slave");
        delay(300);
        return;
    }

    if (bt.connected()){
        bt.write('3');
        Serial.println("Sent 3");
    } else {
        Serial.println("Failed to connect");
    }
    
}