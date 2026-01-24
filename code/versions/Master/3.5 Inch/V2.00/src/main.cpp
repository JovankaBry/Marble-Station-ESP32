#include <Arduino.h>
#include <TFT_eSPI.h>
#include "ui/ui.h"
#include "encoder/encoder.h"
#include "page/containers.h"

static int sel = 0;
static bool inMenu = true;

void draw_menu(){

  draw_rect(100, 60, 300, 100, (sel == 0) ? TFT_RED : TFT_WHITE, 5);
  draw_rect(100, 180, 300, 100, (sel == 1) ? TFT_RED :TFT_WHITE, 5);
  draw_string("Container 1", 125, 90, 4);
  draw_string("Container 2", 125, 210, 4);

}
void setup(){

  ui_init();
  encoderInit();
  draw_menu();

}

void loop(){
  if (inMenu){
    int move = encoderStep();
    if (move != 0){
      sel = !sel;
      draw_menu();
    }
  }

  if (encoderPressed()){
    if (sel == 0){
      container1();
      inMenu = false;
    }
    else if (sel == 1)
    {
      container2();
      inMenu = false;
    }
  }
}