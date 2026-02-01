#include <Arduino.h>
#include "BluetoothSerial.h"
#include "ble/ble.h"
#include "encoder/encoder.h"
#include "app/app.h"

extern uint8_t ballcount;

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

    bt.write('R');
}

void ble_send_itv(uint8_t containerId, uint8_t balls){
    if (balls == 0) return;  

    if (!bt.hasClient()){
        bt.begin("Master", true);
        bt.connect("Station1");
        delay(200);
    }

    char cmd = '0' + balls; 

    while (true){
        if (encoderPressed()) {
            delay(200);
            while(encoderPressed());
            ballcount = 0;   
            return;
        }

        bt.write(cmd);

        delay(2000);
        delay(500);
    }
}
