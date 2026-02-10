#include <Arduino.h>
#include <TFT_eSPI.h>

TFT_eSPI tft = TFT_eSPI();

static int  sel = 0;

void ui_init(){
    tft.init();
    tft.setRotation(1);
    tft.fillScreen(TFT_BLACK);
}

void draw_rect(int32_t x,int32_t y, int32_t w, int32_t h, uint32_t color,uint8_t thickness){

    for (uint8_t i = 0; i < thickness;i++){
        tft.drawRect(x - i, y - i, w + (i * 2), h + (i * 2), color);
    }
}


void draw_string(const char *string, int32_t x, int32_t y, uint8_t font, uint8_t text_size,uint16_t text_colour){

    tft.setTextColor(text_colour, TFT_BLACK);
    tft.setTextSize(text_size);
    tft.setTextFont(font);
    tft.drawString(string, x, y, font);
}

void draw_menu(){
    tft.fillScreen(TFT_BLACK);

    /*============================================== RED =================================================================*/
    draw_rect(10,10,130,130, (sel== 0) ? TFT_BROWN : TFT_WHITE,5);
    draw_string("R",50,45,4,3,TFT_RED);

    /*============================================== GREEN =================================================================*/
    draw_rect(170,10,130,130, (sel== 1) ? TFT_MAGENTA : TFT_WHITE,5);
    draw_string("G",205,45,4,3,TFT_GREEN);

    /*============================================== BLUE =================================================================*/
    draw_rect(330,10,130,130, (sel== 2) ? TFT_MAGENTA : TFT_WHITE,5);
    draw_string("B",370,45,4,3,TFT_BLUE);
}