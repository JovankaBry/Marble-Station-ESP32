#include <Arduino.h>
#include <TFT_eSPI.h>

TFT_eSPI tft;
uint16_t x, y;

uint16_t calData[5] = { 275, 3564, 287, 3513, 7 };

// EC11 pins (from my config)
#define ENC_A   32
#define ENC_B   33
#define ENC_BTN 25   // D pin -> GPIO25, E -> GND

long encoderCount = 0;
int lastA = HIGH;
int lastB = HIGH;

bool lastBtn = HIGH;

void setup() {
  Serial.begin(115200);

  // --- TFT ---
  tft.init();
  tft.setRotation(1);
  tft.setTouch(calData);

  tft.fillScreen(TFT_BLACK);
  tft.setTextColor(TFT_WHITE, TFT_BLACK);
  tft.setTextSize(2);
  tft.setCursor(20, 20);
  tft.println("Touch + EC11 test");

  // --- EC11 ---
  pinMode(ENC_A, INPUT_PULLUP);
  pinMode(ENC_B, INPUT_PULLUP);
  pinMode(ENC_BTN, INPUT_PULLUP);

  lastA = digitalRead(ENC_A);
  lastB = digitalRead(ENC_B);

  Serial.println("Rotate encoder: count++/--");
  Serial.println("Press button: clear screen");
}

void loop() {
  // -------- Touch ----------
  if (tft.getTouch(&x, &y)) {
    tft.fillCircle(x, y, 4, TFT_RED);
    // small delay so it doesn't draw too much
    delay(5);
  }

  // -------- Encoder rotation (simple polling) ----------
  int a = digitalRead(ENC_A);
  int b = digitalRead(ENC_B);

  // Detect a change on A (one common method)
  if (a != lastA) {
    if (a == LOW) {
      // direction depends on B
      if (b == HIGH) encoderCount++;
      else          encoderCount--;

      Serial.printf("Encoder: %ld\n", encoderCount);

      // show count on screen
      tft.setTextColor(TFT_YELLOW, TFT_BLACK);
      tft.setTextSize(2);
      tft.fillRect(20, 45, 200, 20, TFT_BLACK); // clear old number
      tft.setCursor(20, 45);
      tft.printf("Count: %ld", encoderCount);
    }
    // basic debounce
    delay(1);
  }

  lastA = a;
  lastB = b;

  // -------- Button press (simple debounce) ----------
  bool btn = digitalRead(ENC_BTN);

  if (lastBtn == HIGH && btn == LOW) { // pressed
    Serial.println("Button pressed -> clear");
    tft.fillScreen(TFT_BLACK);
    tft.setTextColor(TFT_WHITE, TFT_BLACK);
    tft.setTextSize(2);
    tft.setCursor(20, 20);
    tft.println("Touch + EC11 test");
    encoderCount = 0;
  }

  lastBtn = btn;
}
