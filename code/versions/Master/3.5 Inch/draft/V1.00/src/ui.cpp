#include "ui.h"

static void drawBox(TFT_eSPI &tft, int x, int y, int w, int h,
                    const char *label, bool selected) {
  uint16_t border = selected ? TFT_BLUE : TFT_WHITE;

  tft.drawRoundRect(x, y, w, h, 12, border);
  tft.drawRoundRect(x+1, y+1, w-2, h-2, 12, border);

  tft.setTextColor(TFT_WHITE, TFT_BLACK);
  tft.setTextSize(2);
  tft.setCursor(x + 18, y + (h/2) - 8);
  tft.print(label);
}

void ui_drawMenu(TFT_eSPI &tft, int selectedIndex) {
  int page = selectedIndex / 2;  // 0 = containers 1-2, 1 = containers 3-4

  tft.fillScreen(TFT_BLACK);

  // Title
  tft.setTextColor(TFT_WHITE, TFT_BLACK);
  tft.setTextSize(2);
  tft.setCursor(15, 10);
  tft.print("Select Container  ");
  tft.print(page + 1);
  tft.print("/2");

  // Layout (two boxes)
  int boxX = 30;
  int boxW = tft.width() - 60;
  int boxH = 90;

  int y1 = 55;
  int y2 = 165;

  if (page == 0) {
    drawBox(tft, boxX, y1, boxW, boxH, "Container 1", selectedIndex == 0);
    drawBox(tft, boxX, y2, boxW, boxH, "Container 2", selectedIndex == 1);
  } else {
    drawBox(tft, boxX, y1, boxW, boxH, "Container 3", selectedIndex == 2);
    drawBox(tft, boxX, y2, boxW, boxH, "Container 4", selectedIndex == 3);
  }

  // Hint
  tft.setTextSize(1);
  tft.setCursor(15, tft.height() - 15);
  tft.print("Rotate = select   Press = enter/back");
}