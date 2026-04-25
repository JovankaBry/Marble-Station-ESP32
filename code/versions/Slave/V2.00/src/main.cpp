#include <Arduino.h>
#include "servo.h"
#include "bluetooth.h"

void setup() {
    Serial.begin(115200);
    ble_setup();
    setupServo();
}

void loop() {
    char cmd = ble_read();
    if (cmd == 0) return;

    // Debugging received command from Master
    Serial.print("Received command: ");
    Serial.println(cmd);

    // Control servos based on received command
    if (cmd == '1') {
        servo_1();
    } else if (cmd == '2') {
        servo_2();
    } else if (cmd == '3') {
        servo_3();
    }
}