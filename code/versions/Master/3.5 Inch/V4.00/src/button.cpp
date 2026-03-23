#include <Arduino.h>
#include "button.h"

#define BTN_SELECT 32
#define BTN_CONFIRM 33

void button_init(){
    pinMode(BTN_SELECT, INPUT_PULLUP);
    pinMode(BTN_CONFIRM, INPUT_PULLUP);
}

bool selectPressed(){
    static unsigned long lastTime = 0;

    if (digitalRead(BTN_SELECT) == LOW && millis() - lastTime > 200) {
        lastTime = millis();
        return true;
    }
    return false;
}

bool confirmPressed(){
    static unsigned long lastTime = 0;

    if (digitalRead(BTN_CONFIRM) == LOW && millis() - lastTime > 200) {
        lastTime = millis();
        return true;
    }
    return false;
}