#include <Arduino.h>
#include "servo.h"
#include "display.h"
#include "bluetooth.h"

void setup(){
  Serial.begin(115200);
  servo_setup();
  display_setup();
  ble_setup();
  Serial.println("Station 1 Ready");
}

void loop(){

  char cmd = ble_read();
  if (cmd == 0) return;

  Serial.print("BT received: ");
  Serial.println(cmd);

}