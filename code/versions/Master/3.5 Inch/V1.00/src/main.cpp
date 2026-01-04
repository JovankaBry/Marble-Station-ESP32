#include <Arduino.h>
#include <TFT_eSPI.h>

#include "config.h"
#include "encoder.h"
#include "ui.h"
#include "containers.h"

TFT_eSPI tft;
uint16_t x, y;

enum ViewState { VIEW_MENU, VIEW_CONTAINER };
ViewState view = VIEW_MENU;

int selected = 0;          // 0..3
int currentContainer = 1;  // 1..4

static void drawContainer() {
  switch (currentContainer) {
    case 1: container1_draw(tft); break;
    case 2: container2_draw(tft); break;
    case 3: container3_draw(tft); break;
    case 4: container4_draw(tft); break;
  }
}

void setup() {
  Serial.begin(115200);

  // --- TFT (same as your working code) ---
  tft.init();
  tft.setRotation(1);
  tft.setTouch(CAL_DATA);

  // --- Encoder ---
  encoderInit();

  ui_drawMenu(tft, selected);

  Serial.println("Menu ready. Rotate = select, Press = enter/back.");
}

void loop() {
  
// inside VIEW_CONTAINER section
int step = encoderStep();
bool press = encoderPressed();

if (currentContainer == 1) {
  container1_handle(tft, step, press);
}

// press-to-go-back still works if you want,
// but then don't double-use press.
// Easiest: use LONG press later, but for now:

  if (tft.getTouch(&x, &y)) {
    tft.fillCircle(x, y, 3, TFT_RED);
    delay(5);
  }

  // ----- Encoder rotation -----
  int step = encoderStep();
  if (step != 0 && view == VIEW_MENU) {
    selected += step;
    if (selected < 0) selected = 3;
    if (selected > 3) selected = 0;

    ui_drawMenu(tft, selected);
  }

  // ----- Encoder press -----
  if (encoderPressed()) {
    if (view == VIEW_MENU) {
      currentContainer = selected + 1; // 1..4
      view = VIEW_CONTAINER;
      drawContainer();
    } else {
      view = VIEW_MENU;
      ui_drawMenu(tft, selected);
    }
  }

  delay(2);
}