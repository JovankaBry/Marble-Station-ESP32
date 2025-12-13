#include <Arduino.h>
#include "pages.h"

void drawStation4Page(){

    tft.fillScreen(ST77XX_WHITE);
    tft.setRotation(3);

    tft.drawRect(20, 20, 120, 80, ST77XX_RED);
    tft.drawRect(19, 19, 122, 82, ST77XX_RED);
    tft.drawRect(18, 18, 124, 84, ST77XX_RED);
    tft.drawRect(17, 17, 126, 86, ST77XX_RED);

    tft.setTextSize(2);
    tft.setTextColor(ST77XX_BLACK);
    tft.setCursor(27,50);
    tft.print("Station 4"); 
}