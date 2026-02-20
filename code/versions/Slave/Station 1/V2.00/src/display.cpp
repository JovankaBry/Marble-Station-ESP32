#include <Arduino.h>
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>

#define TFT_CS   5
#define TFT_DC   2
#define TFT_RST  4
#define TFT_BL   15
#define TFT_MOSI 23
#define TFT_SCLK 18

SPIClass vspi(VSPI);
Adafruit_ST7735 tft = Adafruit_ST7735(&vspi, TFT_CS, TFT_DC, TFT_RST);

void display_show_number(int value){
    tft.fillRect(60, 60, 80, 40, ST77XX_WHITE);

    tft.setCursor(70, 60);
    tft.setTextSize(5);
    tft.setTextColor(ST77XX_BLUE);
    tft.print(value);
}

void draw_rect(int32_t x,int32_t y, int32_t w, int32_t h, uint32_t color,uint8_t thickness){

    for (uint8_t i = 0; i < thickness;i++){
        tft.drawRect(x - i, y - i, w + (i * 2), h + (i * 2), color);
    }
}

void draw_string(int x, int y,int TextSize, const char *text, int color){
    tft.setCursor(x,y);
    tft.setTextSize(TextSize);
    tft.setTextColor(color);
    tft.print(text);
}

void draw_station(){
    tft.fillScreen(ST7735_WHITE);
    tft.setRotation(1);
    draw_string(50,10,4, "RED", ST7735_BLUE);
    display_show_number(0);
}

void display_setup(){
    pinMode(TFT_BL, OUTPUT);
    digitalWrite(TFT_BL, HIGH);
    vspi.begin(TFT_SCLK, -1, TFT_MOSI, TFT_CS);
    tft.initR(INITR_GREENTAB);
    draw_station();
}