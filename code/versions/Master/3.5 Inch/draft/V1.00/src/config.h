#pragma once
#include <Arduino.h>

// ===== EC11 pins (same as your working code) =====
#define ENC_A   32
#define ENC_B   33
#define ENC_BTN 25   // D pin -> GPIO25, E -> GND

// ===== Touch calibration (same as your working code) =====
static uint16_t CAL_DATA[5] = { 275, 3564, 287, 3513, 7 };