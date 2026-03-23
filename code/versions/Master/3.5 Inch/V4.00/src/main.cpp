#include <Arduino.h>
#include "bluetooth.h"
#include "button.h"
#include "ui.h"

void setup() {
  Serial.begin(115200);
  button_init();
  ui_init();
  draw_menu();
  ble_setup();
}

void loop() {
  ui_loop();
}
