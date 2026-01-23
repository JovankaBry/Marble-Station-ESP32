#include <Arduino.h>
#include "encoder.h"

// encoder pins
#define ENC_A   32
#define ENC_B   33
#define ENC_BTN 25

static int lastA = HIGH;
static int lastBtn = HIGH;
static uint32_t lastBtnMs = 0;

void encoderInit() {
    pinMode(ENC_A, INPUT_PULLUP);
    pinMode(ENC_B, INPUT_PULLUP);
    pinMode(ENC_BTN, INPUT_PULLUP);

    lastA = digitalRead(ENC_A);
    lastBtn = digitalRead(ENC_BTN);
}

int encoderStep() {
    int a = digitalRead(ENC_A);
    int step = 0;

    if (lastA == HIGH && a == LOW) {
        if (digitalRead(ENC_B) == HIGH)
            step = +1;
        else
            step = -1;
    }

    lastA = a;
    return step;  
}

bool encoderPressed() {
    int btn = digitalRead(ENC_BTN);

    if (lastBtn == HIGH && btn == LOW){
        lastBtn = btn;
        return true;
    }
    lastBtn = btn;
    return false;
}