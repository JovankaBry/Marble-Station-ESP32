#include "menu_ui.h"
#include "../../include/config.h"

static void drawBox(TFT_eSPI &tft,
                    int x, int y, int w, int h,
                    const char *label,
                    bool selected)
{
  uint16_t border = selected ? COLOR_SEL : COLOR_NSEL;

  tft.drawRoundRect(x, y, w, h, 12, border);
  tft.drawRoundRect(x + 1, y + 1, w - 2, h - 2, 12, border);

  tft.setTextColor(COLOR_TEXT, COLOR_BG);
  tft.setTextSize(2);

  tft.setCursor(x + 18, y + (h / 2) - 8);
  tft.print(label);
}

void menu_draw(TFT_eSPI &tft, int selectedIndex)
{

  int page = selectedIndex / 2;

  tft.fillScreen(COLOR_BG);

  tft.setTextColor(COLOR_TEXT, COLOR_BG);
  tft.setTextSize(2);
  tft.setCursor(15, 10);
  tft.print("Menu  (Page ");
  tft.print(page + 1);
  tft.print("/2)");

  int x = 30;
  int w = tft.width() - 60;
  int h = 90;

  int y1 = 55;
  int y2 = 165;

  
  if (page == 0) {
    drawBox(tft, x, y1, w, h, "Container 1", selectedIndex == 0);
    drawBox(tft, x, y2, w, h, "Container 2", selectedIndex == 1);
  } else {
    drawBox(tft, x, y1, w, h, "Container 3", selectedIndex == 2);
    drawBox(tft, x, y2, w, h, "Container 4", selectedIndex == 3);
  }


  tft.setTextSize(1);
  tft.setCursor(15, tft.height() - 15);
  tft.print("Rotate = select   Press = enter");
}
