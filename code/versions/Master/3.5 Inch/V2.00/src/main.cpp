#include <Arduino.h>
#include <TFT_eSPI.h>
#include "ui/ui.h"
#include "ble/ble.h"
#include "encoder/encoder.h"
#include "page/containers.h"

static int sel = 0;
static bool inMenu = true;

enum Page{
  PAGE_MENU,
  PAGE_CONTAINER1,
  PAGE_CONTAINER2
};

static Page currentPage = PAGE_MENU;

void draw_menu(){
  tft.fillScreen(TFT_BLACK);
  draw_string("Select Container!", 0, 0, 2);
  draw_rect(100, 60, 300, 100, (sel == 0) ? TFT_RED : TFT_WHITE, 5);
  draw_rect(100, 180, 300, 100, (sel == 1) ? TFT_RED :TFT_WHITE, 5);
  draw_string("Container 1", 125, 90, 4);
  draw_string("Container 2", 125, 210, 4);

}

void setup(){
  Serial.begin(115200);
  //ble_setup();
  ui_init();
  encoderInit();
  draw_menu();
}

void loop(){

  int move = encoderStep();

  // ===== HOME MENU =====
  if (currentPage == PAGE_MENU){
    if (move != 0){
      sel = !sel;
      draw_menu();
    }

    if (encoderPressed()){
      if (sel == 0){
        container1();
        currentPage = PAGE_CONTAINER1;
      } else {
        container2();
        currentPage = PAGE_CONTAINER2;
      }
    }
  }

  // ===== CONTAINER PAGES =====
  else {
    if (encoderPressed()){
      // BACK pressed
      tft.fillScreen(TFT_BLACK);
      draw_menu();
      currentPage = PAGE_MENU;
    }
  }
}