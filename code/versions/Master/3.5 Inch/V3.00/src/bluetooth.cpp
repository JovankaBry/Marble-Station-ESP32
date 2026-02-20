#include <Arduino.h>
#include "BluetoothSerial.h"
#include "bluetooth.h"
#include "encoder.h"


BluetoothSerial bt;

void ble_setup(){
    bt.begin("Master", true);
    bt.connect("Station1");
}

void ble_send_1(){
    if (!bt.hasClient()) {
        bt.begin("Master", true);
        bt.connect("Station1");
    }

    bt.write('R');
}

void ble_send_2(){
    if (!bt.hasClient()) {
        bt.begin("Master", true);
        bt.connect("Station1");
    }

    bt.write('G');
}

void ble_send_3(){
    if (!bt.hasClient()) {
        bt.begin("Master", true);
        bt.connect("Station1");
    }

    bt.write('B');
}