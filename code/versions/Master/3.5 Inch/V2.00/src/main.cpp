#include <Arduino.h>
#include <TFT_eSPI.h>
#include "ui/ui.h"

void setup(){

  ui_init();
  draw_rect(100, 60, 300, 100, TFT_WHITE);
  draw_rect(100, 180, 300, 100, TFT_WHITE);
  draw_string("Container 1", 125, 90, 4);
  draw_string("Container 2", 125, 210, 4);

}

void loop(){

}