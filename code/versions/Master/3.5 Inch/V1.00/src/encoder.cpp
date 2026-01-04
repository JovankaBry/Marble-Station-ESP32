#include "encoder.h"
#include "config.h"

static int lastA = HIGH;
static int lastB = HIGH;
static int lastBtn = HIGH;

static uint32_t lastBtnMs = 0;

void encoderInit() {
  pinMode(ENC_A, INPUT_PULLUP);
  pinMode(ENC_B, INPUT_PULLUP);
  pinMode(ENC_BTN, INPUT_PULLUP);

  lastA = digitalRead(ENC_A);
  lastB = digitalRead(ENC_B);
  lastBtn = digitalRead(ENC_BTN);
}

int encoderStep() {
  int a = digitalRead(ENC_A);
  int b = digitalRead(ENC_B);

  int step = 0;

  // same style as your working code: detect change on A
  if (a != lastA) {
    if (a == LOW) {
      if (b == HIGH) step = +1;
      else           step = -1;
    }
    delay(1); // small debounce like your working code
  }

  lastA = a;
  lastB = b;
  return step;
}

bool encoderPressed() {
  int btn = digitalRead(ENC_BTN);

  if (lastBtn == HIGH && btn == LOW) {
    uint32_t now = millis();
    if (now - lastBtnMs > 150) { // debounce
      lastBtnMs = now;
      lastBtn = btn;
      return true;
    }
  }

  lastBtn = btn;
  return false;
}