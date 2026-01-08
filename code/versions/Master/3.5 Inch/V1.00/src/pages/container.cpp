#include "container.h"
#include "../../config.h"

static uint8_t currentId = 1;

static int  sel = 0;          // 0=Automatic, 1=Minus, 2=Plus, 3=Back
static bool automaticOn = false;
static int  value = 1;        // 1..3

// Draw thicker round-rect border by drawing multiple outlines
static void drawThickRoundRect(
  TFT_eSPI &tft,
  int x, int y, int w, int h,
  int r,
  uint16_t color,
  int thickness
) {
  for (int i = 0; i < thickness; i++) {
    tft.drawRoundRect(
      x - i, y - i,
      w + i * 2, h + i * 2,
      r, color
    );
  }
}

// Draw thicker rect border by drawing multiple outlines
static void drawThickRect(
  TFT_eSPI &tft,
  int x, int y, int w, int h,
  uint16_t color,
  int thickness
) {
  for (int i = 0; i < thickness; i++) {
    tft.drawRect(
      x - i, y - i,
      w + i * 2, h + i * 2,
      color
    );
  }
}

static void draw(TFT_eSPI &tft) {
  tft.fillScreen(TFT_BLACK);

  // outer panel
  tft.drawRoundRect(10, 10, tft.width() - 20, tft.height() - 20, 18, TFT_WHITE);

  // title
  tft.setTextColor(TFT_WHITE, TFT_BLACK);
  tft.setTextSize(3);
  tft.setCursor(40, 30);
  tft.printf("Container %d", currentId);

  // --- Automatic button ---
  int ax = 60, ay = 90, aw = tft.width() - 120, ah = 70;
  uint16_t autoBg = automaticOn ? TFT_GREEN : TFT_WHITE;

  tft.fillRoundRect(ax, ay, aw, ah, 10, autoBg);

  if (sel == 0) {
    drawThickRoundRect(tft, ax, ay, aw, ah, 10, TFT_BLUE, 3);
  } else {
    tft.drawRoundRect(ax, ay, aw, ah, 10, TFT_BLACK);
  }

  tft.setTextColor(TFT_BLACK, autoBg);
  tft.setTextSize(2);
  tft.setCursor(90, 115);
  tft.print("Automatic");

  // --- Value box ---
  int x = 60, y = 180, w = tft.width() - 120, h = 70;
  int zone = w / 3;

  tft.fillRoundRect(x, y, w, h, 10, TFT_WHITE);

  // Minus zone border (thick blue when selected)
  if (sel == 1) {
    drawThickRect(tft, x, y, zone, h, TFT_BLUE, 3);
  } else {
    tft.drawRect(x, y, zone, h, TFT_BLACK);
  }

  // Plus zone border (thick blue when selected)
  if (sel == 2) {
    drawThickRect(tft, x + 2 * zone, y, zone, h, TFT_BLUE, 3);
  } else {
    tft.drawRect(x + 2 * zone, y, zone, h, TFT_BLACK);
  }

  // Text: -, value, +
  tft.setTextColor(TFT_BLACK, TFT_WHITE);
  tft.setTextSize(4);

  tft.setCursor(x + zone / 2 - 10, y + 18);
  tft.print("-");

  tft.setCursor(x + zone + zone / 2 - 10, y + 18);
  tft.print(value);

  tft.setCursor(x + 2 * zone + zone / 2 - 10, y + 18);
  tft.print("+");

  // --- Back button (bottom-left) ---
  int bx = 20;
  int bh = 40;
  int by = tft.height() - 20 - bh; // 20 px margin from bottom border
  int bw = 90;

  tft.fillRoundRect(bx, by, bw, bh, 10, TFT_WHITE);

  if (sel == 3) {
    drawThickRoundRect(tft, bx, by, bw, bh, 10, TFT_BLUE, 3);
  } else {
    tft.drawRoundRect(bx, by, bw, bh, 10, TFT_BLACK);
  }

  tft.setTextSize(2);
  tft.setTextColor(TFT_BLACK, TFT_WHITE);
  tft.setCursor(bx + 18, by + 12);
  tft.print("Back");
}

void container_enter(TFT_eSPI &tft, uint8_t containerId) {
  currentId = containerId;
  sel = 0;
  automaticOn = false;
  value = 1;
  draw(tft);
}

bool container_update(TFT_eSPI &tft, int encStep, bool encPress) {
  if (encStep != 0) {
    sel += encStep;
    if (sel < 0) sel = 3;
    if (sel > 3) sel = 0;
    draw(tft);
  }

  if (encPress) {
    if (sel == 0) {
      automaticOn = !automaticOn;
      draw(tft);
    } else if (sel == 1 && value > 1) {
      value--;
      draw(tft);
    } else if (sel == 2 && value < 3) {
      value++;
      draw(tft);
    } else if (sel == 3) {
      return true; // go back
    }
  }

  return false;
}