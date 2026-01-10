#include <Arduino.h>
#include <TFT_eSPI.h>

TFT_eSPI tft = TFT_eSPI();

void ui_init() {

  tft.init();
  tft.setRotation(1);
  tft.fillScreen(TFT_BLACK);
  tft.setCursor(0,0);
  tft.setTextColor(TFT_WHITE);
  tft.setTextSize(2);
  tft.setTextFont(2);
  tft.println("Hello World");

}


void draw_rect(int32_t x,int32_t y, int32_t w, int32_t h, uint32_t color){

    tft.drawRect(x, y, w, h, color);

}


void draw_string(const char *string, int32_t x, int32_t y, uint8_t font){

    tft.drawString(string, x, y, font);

}