#include <Arduino.h>
#include <TFT_eSPI.h>
#include "ui/ui.h"
#include "app/app.h"


void back(bool selected){

    draw_rect(15,260,90,40, selected ? TFT_RED : TFT_WHITE, 1);
    draw_string("Back", 35,265,2);
}

void activate(bool selected){
    draw_rect(100, 30, 300, 100, selected ? TFT_RED : TFT_WHITE, 5);
    draw_string("1 Ball", 180,60,4);
}

void minus(bool selected){
    draw_rect(100,150,80,100, selected ? TFT_RED : TFT_WHITE, 5);
    draw_string("-", 133,175,4);
}

void plus(bool selected){
    draw_rect(320,150,80,100, selected ? TFT_RED : TFT_WHITE, 5);
    draw_string("+", 350,175,4);
}

void ball_counter(bool selected, uint8_t n_ball){
    draw_rect(190,150,120,100, selected ? TFT_RED : TFT_WHITE, 5);
    char buf[2];
    sprintf(buf, "%d", n_ball);
    draw_string(buf,233,175,4);
}

void container1(int c1_sel, uint8_t ballcount){

    tft.fillScreen(TFT_BLACK);
    activate(c1_sel == 0);
    minus(c1_sel == 1);
    ball_counter(c1_sel == 2, ballcount);
    plus(c1_sel == 3);
    back(c1_sel == 4);
    
}

void container2(int c2_sel){

    tft.fillScreen(TFT_BLACK);
    activate(c2_sel == 0);
    back(c2_sel == 1);
}