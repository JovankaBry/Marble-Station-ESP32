#include <Arduino.h>
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
#include "pages.h"

// Your fixed pins
#define TFT_CS   5
#define TFT_DC   2
#define TFT_RST  4
#define TFT_BL   15  // backlight
#define TFT_MOSI 23
#define TFT_SCLK 18

// Buttons
#define LEFT 19
#define DOWN 14
#define UP   25
#define RIGHT 26
#define OK 27

// Use hardware SPI (MOSI=23, SCLK=18 on ESP32)
//Adafruit_ST7735 tft(TFT_CS, TFT_DC, TFT_RST,TFT_MOSI, TFT_SCLK);

SPIClass vspi(VSPI);
Adafruit_ST7735 tft = Adafruit_ST7735(&vspi, TFT_CS, TFT_DC, TFT_RST);

bool station1selected = true;
int currentPage = 1;

//---------------------------------------Functions----------------------------------------------------------------------------------------
void ReadButtons(){
  if (digitalRead(LEFT) == LOW)  Serial.println("LEFT");
  if (digitalRead(DOWN) == LOW)  Serial.println("DOWN");
  if (digitalRead(UP) == LOW)    Serial.println("UP");
  if (digitalRead(RIGHT) == LOW) Serial.println("RIGHT");
  if (digitalRead(OK) == LOW)    Serial.println("OK");
  delay(50);
}

void updateMenu(){
  if(digitalRead(OK) == LOW && station1selected) Serial.println("to station 2");
  delay(200);
}

//--------------------------------------Setup------------------------------------------------------------------------------------------------
void setup() {
  Serial.begin(115200);

  vspi.begin(TFT_SCLK, -1, TFT_MOSI, TFT_CS);

  pinMode(LEFT, INPUT_PULLUP);
  pinMode(DOWN, INPUT_PULLUP);
  pinMode(UP, INPUT_PULLUP);
  pinMode(RIGHT, INPUT_PULLUP);
  pinMode(OK, INPUT_PULLUP);
  
  pinMode(TFT_BL, OUTPUT);
  digitalWrite(TFT_BL, HIGH);

  // Init display
  tft.initR(INITR_GREENTAB);

  drawStation1Page();

}

void loop() {

  //Pressing Right Button
  if (digitalRead(RIGHT) == LOW) {
    if (currentPage == 1) {
      currentPage = 2;
      drawStation2Page();
      Serial.println("to station 2");
    } else if (currentPage == 2) {
      currentPage = 3;
      drawStation3Page();
      Serial.println("to station 3");
    }else if (currentPage == 3){
      currentPage = 4;
      drawStation4Page();
      Serial.println("to station 4");
    }else {
      currentPage = 1;
      drawStation1Page();
      Serial.println("back to station 1");
    }
    delay(150); 
  }

  //Pressing Left Button
if (digitalRead(LEFT) == LOW) {
  if (currentPage == 1) {
    currentPage = 4;
    drawStation4Page();
    Serial.println("to station 4");
  }
  else if (currentPage == 4) {
    currentPage = 3;
    drawStation3Page();
    Serial.println("to station 3");
  }
  else if (currentPage == 3) {
    currentPage = 2;
    drawStation2Page();
    Serial.println("to station 2");
  }else{
    currentPage = 1;
    drawStation1Page();
    Serial.println("to station 1");
  }
}
  delay(150);
}
