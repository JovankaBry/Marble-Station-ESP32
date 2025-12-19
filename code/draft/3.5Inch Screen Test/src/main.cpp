#include <Arduino.h>
#include <TFT_eSPI.h>

TFT_eSPI tft;
uint16_t x, y;

uint16_t calData[5] = { 275, 3564, 287, 3513, 7};

void setup() {
  Serial.begin(115200);

  tft.init();
  tft.setRotation(1);
  tft.setTouch(calData);

  tft.fillScreen(TFT_BLACK);
  tft.setTextColor(TFT_WHITE, TFT_BLACK);
  tft.setTextSize(2);
  tft.setCursor(20, 20);
  tft.println("Touch the screen");
}

void loop() {
  if (tft.getTouch(&x, &y)) {
    Serial.printf("x=%u y=%u\n", x, y);
    tft.fillCircle(x, y, 4, TFT_RED);
    delay(1);
  }
}
