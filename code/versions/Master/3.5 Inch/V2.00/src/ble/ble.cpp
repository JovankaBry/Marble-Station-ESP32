#include <Arduino.h>
#include "BluetoothSerial.h"
#include "ble/ble.h"

BluetoothSerial bt;

void ble_setup(){
    bt.begin("Master", true);
    bt.connect("Station1");
}

void ble_send_release(uint8_t containerId){
    if (!bt.hasClient()) {
        bt.begin("Master", true);
        bt.connect("Station1");
    }

    char cmd = '0' + containerId;
    bt.write(cmd);
}