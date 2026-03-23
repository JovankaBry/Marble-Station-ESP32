#include <Arduino.h>
#include "bluetooth.h"
#include "BluetoothSerial.h"

BluetoothSerial bt;

void ble_setup(){
    bt.begin("Slave");
}

char ble_read(){
    if (bt.available()) {
        return bt.read();
    }
    return 0;
}