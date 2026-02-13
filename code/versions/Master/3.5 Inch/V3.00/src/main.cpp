#include <Arduino.h>
#include "ui.h"
#include "encoder.h"

void setup(){
  encoderInit();
  ui_init();
  draw_menu();
}

void loop(){
  ui_loop();
}