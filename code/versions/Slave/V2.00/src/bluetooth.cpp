#include <Arduino.h>
#include "bluetooth.h"
#include "BluetoothSerial.h"

BluetoothSerial bt;

// Bluetooth Setup
void ble_setup(){
    bt.begin("Slave");
}

// Read incoming Bluetooth char
char ble_read(){
    if (bt.available()) {
        return bt.read();
    }
    return 0;
}