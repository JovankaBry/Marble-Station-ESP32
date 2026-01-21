#include <Arduino.h>
#include <ESP32Encoder.h>
#include "encoder.h"

#define ENC_A 32
#define ENC_B 33
#define ENC_BTN 25

ESP32Encoder encoder;

static int last;

void encoder_init(){
    encoder.attachHalfQuad(ENC_A, ENC_B);
    pinMode(ENC_BTN, INPUT_PULLUP);
}

int encoder_read(){
    int now = encoder.getCount();
    int diff = now -last;
    last = now;
    return diff;
}

bool encoder_pressed(){
    return digitalRead(ENC_BTN) == LOW;
}