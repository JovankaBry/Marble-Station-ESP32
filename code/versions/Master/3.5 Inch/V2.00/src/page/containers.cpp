#include <Arduino.h>
#include <TFT_eSPI.h>
#include "ui/ui.h"



void container1(){

    tft.fillScreen(TFT_BLACK);
    draw_string("Welcome To Container 1", 125, 90, 4);

}

void container2(){

    tft.fillScreen(TFT_BLACK);
    draw_string("Container 2", 125, 90, 4);
    
}