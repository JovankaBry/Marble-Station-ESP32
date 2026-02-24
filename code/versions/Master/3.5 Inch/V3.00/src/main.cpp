#include <Arduino.h>
#include "ui.h"
#include "encoder.h"
#include "bluetooth.h"

void setup(){
  Serial.begin(115200);
  encoderInit();
  ui_init();
  draw_menu();
  ble_setup();
}

void loop(){
  ui_loop();
}