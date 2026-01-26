#include <Arduino.h>
#include <TFT_eSPI.h>
#include "ui/ui.h"

static int sel = 1;

void back(){

    draw_rect(15,260,90,40, TFT_RED, 1);
    draw_string("Back", 35,265,2);
}

void container1(){

    tft.fillScreen(TFT_BLACK);
    draw_string("Welcome To Container 1", 125, 90, 4);
    back();
}

void container2(){

    tft.fillScreen(TFT_BLACK);
    draw_string("Container 2", 125, 90, 4);
    back();
}