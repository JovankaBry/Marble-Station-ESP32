#include <Arduino.h>
#include <TFT_eSPI.h>
#include "ui/ui.h"


void back(bool selected){

    draw_rect(15,260,90,40, selected ? TFT_RED : TFT_WHITE, 1);
    draw_string("Back", 35,265,2);
}

void activate(bool selected){
    draw_rect(100, 30, 300, 100, selected ? TFT_RED : TFT_WHITE, 5);
    draw_string("1 Ball", 180,60,4);
}

void container1(int c1_sel){

    tft.fillScreen(TFT_BLACK);
    activate(c1_sel == 0);
    back(c1_sel == 1);
}

void container2(int c2_sel){

    tft.fillScreen(TFT_BLACK);
    activate(c2_sel == 0);
    back(c2_sel == 1);
}