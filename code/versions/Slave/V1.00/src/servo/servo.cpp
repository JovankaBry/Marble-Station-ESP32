#include <Arduino.h>
#include <Servo.h>

#define SERVO_PIN 19

Servo servo;

void servo_setup() {
    servo.attach(SERVO_PIN);
}

void open_gate(int32_t t){
    servo.write(0);
    delay(t);
}

void close_gate(int32_t t){
    servo.write(90);
    delay(t);
}