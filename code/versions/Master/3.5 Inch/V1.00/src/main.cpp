#include <Arduino.h>
#include <TFT_eSPI.h>

#include "encoder/encoder.h"
#include "ui/menu_ui.h"
#include "pages/container.h"

TFT_eSPI tft;

enum Page { PAGE_MENU, PAGE_CONTAINER };
static Page currentPage = PAGE_MENU;

static int menuSel = 0;              // 0..3
static uint8_t activeContainer = 1;  // 1..4

void setup() {
  Serial.begin(115200);

  tft.init();
  tft.setRotation(1);
  tft.fillScreen(TFT_BLACK);

  encoderInit();

  menu_draw(tft, menuSel);
}

void loop() {
  int step = encoderStep();
  bool press = encoderPressed();

  if (currentPage == PAGE_MENU) {
    if (step != 0) {
      menuSel += step;
      if (menuSel < 0) menuSel = 3;
      if (menuSel > 3) menuSel = 0;
      menu_draw(tft, menuSel);
    }

    if (press) {
      activeContainer = menuSel + 1;
      container_enter(tft, activeContainer);
      currentPage = PAGE_CONTAINER;
    }
  }
  else if (currentPage == PAGE_CONTAINER) {
    bool goBack = container_update(tft, step, press);
    if (goBack) {
      currentPage = PAGE_MENU;
      menu_draw(tft, menuSel);
    }
  }

  delay(1);
}