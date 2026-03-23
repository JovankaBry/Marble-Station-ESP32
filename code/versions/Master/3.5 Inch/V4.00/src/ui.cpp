#include <Arduino.h>
#include <TFT_eSPI.h>
#include "button.h"
#include "bluetooth.h"

TFT_eSPI tft = TFT_eSPI();

static int  sel = 1;
static bool autoMode = false;

static int countR = 0;
static int countG = 0;
static int countB = 0;

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
    draw_rect(10,10,130,130, (sel == 1) ? TFT_BROWN : TFT_WHITE,5);
    draw_string("R",50,45,4,3,TFT_RED);

    draw_rect(10,160,130,100, (sel == 4) ? TFT_BROWN : TFT_WHITE,5);
    tft.setTextColor(TFT_RED);
    tft.setTextSize(3);
    tft.drawString(String(countR), 55, 180);

    /*============================================== GREEN =================================================================*/
    draw_rect(170,10,130,130, (sel == 2) ? TFT_BROWN : TFT_WHITE,5);
    draw_string("G",205,45,4,3,TFT_GREEN);

    draw_rect(170,160,130,100, (sel == 5) ? TFT_BROWN : TFT_WHITE,5);
    tft.setTextColor(TFT_GREEN);
    tft.setTextSize(3);
    tft.drawString(String(countG), 215, 180);

    /*============================================== BLUE =================================================================*/
    draw_rect(330,10,130,130, (sel == 3) ? TFT_BROWN : TFT_WHITE,5);
    draw_string("B",370,45,4,3,TFT_BLUE);

    draw_rect(330,160,130,100, (sel == 6) ? TFT_BROWN : TFT_WHITE,5);
    tft.setTextColor(TFT_BLUE);
    tft.setTextSize(3);
    tft.drawString(String(countB), 370, 180);


    /*============================================== AUTO =================================================================*/
    uint16_t autoColor = autoMode ? TFT_GREEN :
                     (sel == 7 ? TFT_BROWN : TFT_WHITE);
    draw_rect(170,275,130,40, autoColor, 5);
    draw_string("Auto",210,285,4,1,TFT_WHITE);
    
}

void ui_loop(){

    if (selectPressed()){
        sel += 1;

        if(sel < 1) sel = 7;
        if(sel > 7) sel = 1;

        draw_menu();
    }

    if(confirmPressed()){
        switch(sel){

            case 1:
                Serial.println("Red selected");
                ble_send_1();
                break;
            
            case 2:
                Serial.println("Green selected");
                ble_send_2();
                break;  

            case 3:
                Serial.println("Blue selected");
                ble_send_3();
                break;   

            case 4:
                Serial.println("Case 4");
                countR++;
                if (countR > 3) countR = 0;

                draw_menu();
                Serial.println("CountR: ");
                Serial.println(countR);
                break;
            
            case 5:
                Serial.println("Case 5");
                countG++;
                if (countG > 3) countG = 0;

                draw_menu();
                Serial.println("CountG: ");
                Serial.println(countG);
                break;
            
            case 6:
                Serial.println("Case 5");
                countB++;
                if (countB > 3) countB = 0;

                draw_menu();
                Serial.println("CountB: ");
                Serial.println(countB);
                break;
            
            case 7:
                Serial.println("Case 7");
                autoMode = !autoMode;
                draw_menu();

                Serial.println(countR);
                Serial.println(countG);
                Serial.println(countB);                                
                break;
        }
    }
}