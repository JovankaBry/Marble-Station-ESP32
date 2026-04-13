#include <Arduino.h>
#include "button.h"

#define BTN_SELECT 32
#define BTN_CONFIRM 33

// Button setup
void button_init(){
    pinMode(BTN_SELECT, INPUT_PULLUP);
    pinMode(BTN_CONFIRM, INPUT_PULLUP);
}

// Check if the select button is pressed
bool selectPressed(){
    if (digitalRead(BTN_SELECT) == LOW) {
        delay(200);
        return true;
    }
    return false;
}

// Check if the confirm button is pressed
bool confirmPressed(){
    if (digitalRead(BTN_CONFIRM) == LOW) {
        delay(200);
        return true;
    }
    return false;
}