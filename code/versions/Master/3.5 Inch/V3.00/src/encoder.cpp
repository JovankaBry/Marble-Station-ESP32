#include <Arduino.h>
#include "encoder.h"
#include "ui.h"

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

//Chat GPT 5.2
//It sometimes clicked 2 times, so i have 2 inputs instead of 1, what should i do
bool encoderPressed() {
  static bool latched = false;
  static uint32_t t0 = 0;
  const uint32_t debounceMs = 80;   // try 80–150ms

  int btn = digitalRead(ENC_BTN);

  // Button released -> reset latch
  if (btn == HIGH) {
    latched = false;
    t0 = 0;
    return false;
  }

  // Button is LOW (pressed)
  if (!latched) {
    // start debounce timer
    if (t0 == 0) t0 = millis();

    // if still LOW long enough -> accept press ONCE
    if (millis() - t0 >= debounceMs) {
      latched = true;
      return true;
    }
  }

  return false;
}