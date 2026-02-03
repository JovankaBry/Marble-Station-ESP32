#include <Arduino.h>
#include "servo/servo.h"
#include "BLE/ble.h"
#include "display/display.h"
#include "sensors/sensor1.h"



void setup() {
  Serial.begin(115200);
  servo_setup();
  ble_setup();
  display_setup();
  Serial.print("Slave ready");
}

void loop() {

    if (sensor1_update()) {
    int count = sensor1_get_count();
    display_show_number(count);

    Serial.print("Ball count: ");
    Serial.println(count);
  }

  char cmd = ble_read();
  if (cmd == 0) return;

  Serial.print("BT received: ");
  Serial.println(cmd);

  if (cmd == 'R'){
    open_gate(500);
    return;
  }
  
  if (cmd >= '1' && cmd <= '4') {
    uint8_t balls = cmd - '0';
    open_gate(balls * 500);   
  }
}
