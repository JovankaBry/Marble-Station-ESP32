#include <Arduino.h>
#include <ESP32Servo.h>

Servo myServo;

void setup() {
  Serial.begin(115200);

  myServo.attach(13);   // Servo signal on GPIO 13
  Serial.println("Servo ready");
}

void loop() {
  myServo.write(150);    // move to 90°
  delay(4000);

  myServo.write(90);    // move to 90°
  delay(150);
}