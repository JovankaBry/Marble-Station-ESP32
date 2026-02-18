#include <Arduino.h>
#include <ESP32Servo.h>

Servo myServo;


void setup() {
  Serial.begin(115200);

  myServo.attach(13);   // Servo signal on GPIO 13
  Serial.println("Servo ready");
}

void drop_ball(){
  
  myServo.write(110); // Close / Drop Ball
  delay(2000);

  myServo.write(15);
  delay(300);

  myServo.write(0);
  delay(300);

}

void loop() {
  drop_ball();
}