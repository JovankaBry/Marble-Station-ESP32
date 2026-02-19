#include <Arduino.h>
#include "ui.h"
#include "encoder.h"

void setup(){
  Serial.begin(115200);
  encoderInit();
  ui_init();
  draw_menu();
}

void loop(){
  ui_loop();
}