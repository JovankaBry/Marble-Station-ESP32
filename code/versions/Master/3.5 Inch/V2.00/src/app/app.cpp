#include <Arduino.h>
#include <TFT_eSPI.h>

#include "ui/ui.h"
#include "encoder/encoder.h"
#include "page/containers.h"
#include "ble/ble.h"


static int sel   = 0;  
static int c1_sel = 0; 
static int c2_sel = 0;
uint8_t ballcount = 0;

enum Page {
  PAGE_MENU,
  PAGE_CONTAINER1,
  PAGE_CONTAINER2
};
 
static Page currentPage = PAGE_MENU;

static void draw_menu() {
  tft.fillScreen(TFT_BLACK);
  draw_string("Select Container!", 0, 0, 2);

  draw_rect(100, 60, 300, 100, (sel == 0) ? TFT_RED : TFT_WHITE, 5);
  draw_rect(100, 180, 300, 100, (sel == 1) ? TFT_RED : TFT_WHITE, 5);

  draw_string("Container 1", 125, 90, 4);
  draw_string("Container 2", 125, 210, 4);
}

void app_setup() {
  ui_init();
  encoderInit();
  draw_menu();
}

void app_loop() {
  int move = encoderStep();

  // ====== MENU ======
  if (currentPage == PAGE_MENU) {
    if (move != 0) {
      sel = !sel;
      draw_menu();
    }

    if (encoderPressed()) {
      if (sel == 0) {
        c1_sel = 0;              
        container1(c1_sel, ballcount);
        currentPage = PAGE_CONTAINER1;
      } else {
        c2_sel = 0;              
        container2(c2_sel);
        currentPage = PAGE_CONTAINER2;
      }
    }
    return;
  }

  // ===== CONTAINER 1 =====
  if (currentPage == PAGE_CONTAINER1) {
    if (move != 0) {
      c1_sel += move;

      if (c1_sel < 0) c1_sel = 4;
      if (c1_sel > 4) c1_sel = 0;
      container1(c1_sel, ballcount);
    }

    if (encoderPressed()) {
      if (c1_sel == 4) {    // Back  
        draw_menu();
        currentPage = PAGE_MENU;
        return;
      } 

      if (c1_sel == 1){   // Minus
        if (ballcount > 0) ballcount--;
        container1(c1_sel,ballcount);
        return;
      }
      
      if (c1_sel == 2){
        container1(c1_sel,ballcount);
        ble_send_itv(1,ballcount);
        return;
      }

      if (c1_sel==3){   //Minus
        if (ballcount < 4) ballcount++;
        container1(c1_sel,ballcount);
        return;
      }
      else {    //Releasing 1 Ball
        Serial.println("Realising Container 1");
        ble_send_release(1);
        delay(150);
        ballcount = 0;
        c1_sel = 0;
        return;
      }
    }
    return;
  }

  // ===== CONTAINER 2 =====
  if (currentPage == PAGE_CONTAINER2) {
    if (move != 0) {
      c2_sel = !c2_sel;
      container2(c2_sel);
    }

    if (encoderPressed()) {
      if (c2_sel == 1) {
        draw_menu();
        currentPage = PAGE_MENU;
      } else {
        container2(c2_sel);
      }
    }
    return;
  }
}
