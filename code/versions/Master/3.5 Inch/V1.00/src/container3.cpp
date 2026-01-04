#include "containers.h"

void container3_draw(TFT_eSPI &tft) {
  tft.fillScreen(TFT_BLACK);
  tft.setTextColor(TFT_WHITE, TFT_BLACK);
  tft.setTextSize(3);
  tft.setCursor(20, 20);
  tft.println("Container 3");

  tft.setTextSize(1);
  tft.setCursor(20, 80);
  tft.println("Press encoder button to go back.");
}