#include <Arduino.h>
#include "servo/servo.h"
#include "BLE/ble.h"

void setup() {
  Serial.begin(115200);
  servo_setup();
  ble_setup();
  Serial.print("Slave ready");
}

void loop() {
  char cmd = ble_read();

  if (cmd){
    Serial.print("BT received: ");
    Serial.println(cmd);
  }

  if (cmd == '1'){
    Serial.println("OPEN Gate");
    open_gate(5000);
  }else{
    Serial.println("CLOSE Gate");
    close_gate(5000);
  }
}