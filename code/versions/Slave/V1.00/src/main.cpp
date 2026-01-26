#include <Arduino.h>
#include "servo/servo.h"

void setup() {
  servo_setup();
}

void loop() {
  open_gate(2000);
  close_gate(2000);
}