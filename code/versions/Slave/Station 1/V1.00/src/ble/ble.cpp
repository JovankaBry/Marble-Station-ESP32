#include <Arduino.h>
#include "BluetoothSerial.h"
#include "ble.h"

BluetoothSerial bt;

void ble_setup(){
    bt.begin("Station1");
}

char ble_read(){
    if (bt.available()){
        return bt.read();
    }
    return 0;
}