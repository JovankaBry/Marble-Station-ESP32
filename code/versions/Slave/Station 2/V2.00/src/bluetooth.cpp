#include <Arduino.h>
#include "BluetoothSerial.h"
#include "bluetooth.h"

BluetoothSerial bt;

void ble_setup(){
    bt.begin("Station2");
}

char ble_read(){
    if (bt.available()){
        return bt.read();
    }
    return 0;
}