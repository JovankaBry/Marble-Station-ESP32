#include <Arduino.h>
#include <Servo.h>

#define SERVO_PIN 19

Servo servo;

void servo_setup() {
    servo.attach(SERVO_PIN);
    servo.write(90);
    delay(300);
}

void open_gate(int32_t t){
    servo.write(0);
    delay(t);
    servo.write(90);
    delay(300);
}