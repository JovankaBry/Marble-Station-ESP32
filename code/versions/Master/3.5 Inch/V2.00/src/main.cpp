#include <Arduino.h>
#include <TFT_eSPI.h>
#include "ui/ui.h"
#include "encoder/encoder.h"

void setup(){

  ui_init();
  encoder_init();

  int move = encoder_read();
  bool ok = encoder_pressed();

  draw_rect(100, 60, 300, 100, TFT_WHITE, 5);
  draw_rect(100, 180, 300, 100, TFT_WHITE,5);
  draw_string("Container 1", 125, 90, 4);
  draw_string("Container 2", 125, 210, 4);

}

void loop(){

}