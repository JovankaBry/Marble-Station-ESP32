#include <Arduino.h>
#include "BluetoothSerial.h"
#include "ble/ble.h"

BluetoothSerial bt;

void ble_setup(){
    bt.begin("Master", true);
    bt.connect("Station1");
}

void ble_send(char c){
    bt.write(c);
}