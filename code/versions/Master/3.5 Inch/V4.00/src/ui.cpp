#include <Arduino.h>
#include <TFT_eSPI.h>
#include "button.h"
#include "bluetooth.h"

TFT_eSPI tft = TFT_eSPI();

static int  sel = 1;
static bool autoMode = false;

static int autoStep = 0;
static unsigned long lastAutoTime = 0;

static int countR = 0;
static int countG = 0;
static int countB = 0;

// UI setup
void ui_init(){
    tft.init();
    tft.setRotation(1);
    tft.fillScreen(TFT_BLACK);
}

// Function to draw a rectangle with a specified thickness
void draw_rect(int32_t x,int32_t y, int32_t w, int32_t h, uint32_t color,uint8_t thickness){

    for (uint8_t i = 0; i < thickness;i++){
        tft.drawRect(x - i, y - i, w + (i * 2), h + (i * 2), color);
    }
}

// Function to draw a string with specified font, size and color
void draw_string(const char *string, int32_t x, int32_t y, uint8_t font, uint8_t text_size,uint16_t text_colour){

    tft.setTextColor(text_colour, TFT_BLACK);
    tft.setTextSize(text_size);
    tft.setTextFont(font);
    tft.drawString(string, x, y, font);
}

// Function to draw the menu on the TFT display
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
    uint16_t autoColor;
    if (autoMode)       autoColor = TFT_GREEN;
    else if (sel == 7)  autoColor = TFT_BROWN;
    else                autoColor = TFT_WHITE;

    draw_rect(170, 275, 130, 40, autoColor, 5);
    draw_string("Auto", 210, 285, 4, 1, TFT_WHITE);
}

// Promt: so in master i can choose between 1-3 for each r,g,b static int countR = 0;
// static int countG = 0; static int countB = 0; so when i click Auto or case 7 it will automartically looping
// the ball, for instance i chose R = 1 G = 2 B = 1,it will output 1 R 2G 1B forever ultil i press the button again (break the loop=)
// how do i do that simple
// Modell: GPT-5.0; 23.03.2026 [KI 22]
void auto_loop() {

    if (!autoMode) return;

    if (millis() - lastAutoTime < 1000) return; // 1 ball per second
    lastAutoTime = millis();

    // total steps
    int total = countR + countG + countB;
    if (total == 0) return;

    autoStep++;
    if (autoStep > total) autoStep = 1;

    // decide which color
    if (autoStep <= countR) {
        Serial.println("Auto R");
        ble_send_1();
    }
    else if (autoStep <= countR + countG) {
        Serial.println("Auto G");
        ble_send_2();
    }
    else {
        Serial.println("Auto B");
        ble_send_3();
    }
}

// Ende der KI-generierten Anweisungsfolge [KI 22]

// Function to handle user input and update the menu accordingly
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
                countR++;
                if (countR > 3) countR = 0; // Resets count to 0 after reaching 3

                draw_menu();    // Update the menu to reflect the new count
                Serial.println("CountR: ");
                Serial.println(countR);
                break;
            
            case 5:
                countG++;
                if (countG > 3) countG = 0;

                draw_menu();
                Serial.println("CountG: ");
                Serial.println(countG);
                break;
            
            case 6:
                countB++;
                if (countB > 3) countB = 0;

                draw_menu();
                Serial.println("CountB: ");
                Serial.println(countB);
                break;
            
            case 7:
                autoMode = !autoMode;

                if (autoMode) {
                    autoStep = 0;
                    Serial.println("AUTO ON");
                } else {
                    Serial.println("AUTO OFF");
                }

                draw_menu();
                break;
        }
    }
}