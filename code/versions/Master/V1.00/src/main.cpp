#include <Arduino.h>
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>

// Your fixed pins
#define TFT_CS   5
#define TFT_DC   2
#define TFT_RST  4
#define TFT_BL   15  // backlight

// Use hardware SPI (MOSI=23, SCLK=18 on ESP32)
Adafruit_ST7735 tft(TFT_CS, TFT_DC, TFT_RST);

void setup() {
  // Backlight on
  pinMode(TFT_BL, OUTPUT);
  digitalWrite(TFT_BL, HIGH);

  // Init display
  tft.initR(INITR_BLACKTAB);  // try INITR_GREENTAB if colors look weird
  tft.fillScreen(ST77XX_BLACK);

  tft.setTextColor(ST77XX_WHITE);
  tft.setTextSize(1);          // bigger text
  tft.setCursor(10, 20);
  tft.print("Hello World");
}

void loop() {
  // nothing :) screen just shows text
}
