#include "containers.h"
#include <Arduino.h>

// ---- Container 1 state ----
static int selectedBtn = 0;   // 0 = range button, 1 = output button
static int rangeVal = 1;      // 1 or 2

static void drawButton(TFT_eSPI &tft, int x, int y, int w, int h,
                       const char *title, const char *valueText,
                       bool selected)
{
  uint16_t border = selected ? TFT_BLUE : TFT_RED;

  tft.drawRoundRect(x, y, w, h, 12, border);
  tft.drawRoundRect(x + 1, y + 1, w - 2, h - 2, 12, border);

  tft.setTextColor(TFT_WHITE, TFT_BLACK);

  tft.setTextSize(2);
  tft.setCursor(x + 15, y + 15);
  tft.print(title);

  if (valueText && valueText[0] != '\0') {
    tft.setTextSize(3);
    tft.setCursor(x + 15, y + 45);
    tft.print(valueText);
  }
}

static void drawPage(TFT_eSPI &tft)
{
  tft.fillScreen(TFT_BLACK);

  // Title
  tft.setTextColor(TFT_WHITE, TFT_BLACK);
  tft.setTextSize(2);
  tft.setCursor(15, 10);
  tft.print("Container 1");

  int x = 30;
  int w = tft.width() - 60;
  int h = 90;

  // Button 1: Range 1-2
  char rangeText[8];
  snprintf(rangeText, sizeof(rangeText), "%d", rangeVal);
  drawButton(tft, x, 55,  w, h, "Range (1-2)", rangeText, selectedBtn == 0);

  // Button 2: Output 1 ball
  drawButton(tft, x, 165, w, h, "Output", "1 ball", selectedBtn == 1);

  // Footer hint
  tft.setTextSize(1);
  tft.setCursor(15, tft.height() - 15);
  tft.print("Rotate = select   Press = action");
}

void container1_draw(TFT_eSPI &tft)
{
  // reset selection when entering page
  selectedBtn = 0;
  rangeVal = 1;

  drawPage(tft);
}

// Called repeatedly while you are inside Container 1
void container1_handle(TFT_eSPI &tft, int step, bool pressed)
{
  bool needRedraw = false;

  // rotate -> change selection between 2 buttons
  if (step != 0) {
    if (step > 0) selectedBtn++;
    else          selectedBtn--;

    if (selectedBtn < 0) selectedBtn = 1;
    if (selectedBtn > 1) selectedBtn = 0;

    needRedraw = true;
  }

  // press -> activate selected button
  if (pressed) {
    if (selectedBtn == 0) {
      // toggle range 1 <-> 2
      rangeVal = (rangeVal == 1) ? 2 : 1;
      Serial.printf("[C1] Range set to: %d\n", rangeVal);
      needRedraw = true;
    }
    else if (selectedBtn == 1) {
      // output 1 ball (later: Bluetooth send)
      Serial.printf("[C1] OUTPUT 1 BALL (range=%d)\n", rangeVal);

      // TODO later:
      // sendBluetoothCommand(rangeVal, 1);

      // small visual feedback: flash text
      tft.setTextColor(TFT_GREEN, TFT_BLACK);
      tft.setTextSize(2);
      tft.setCursor(30, 130);
      tft.print("SENT!");
      delay(150);
      needRedraw = true;
    }
  }

  if (needRedraw) {
    drawPage(tft);
  }
}