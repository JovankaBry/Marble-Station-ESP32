#include <Arduino.h>
#include "BluetoothSerial.h"
#include "bluetooth.h"

BluetoothSerial bt;

// Bluetooth setup
void ble_setup(){
    bt.begin("Master", true);
    bt.connect("Slave");
    delay(300);
}

// Send "1" to the slave
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

// Send "2" to the slave
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

// Send "3" to the slave
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