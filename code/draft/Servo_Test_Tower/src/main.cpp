#include <Arduino.h>
#include <Servo.h>

#define SERVO_PIN 19

Servo servo;

void setup() {
  servo.attach(SERVO_PIN);
  servo.write(90);    // center position
}

void loop() {
  servo.write(0);
  delay(1000);

  servo.write(90);   
  delay(1000);
}
