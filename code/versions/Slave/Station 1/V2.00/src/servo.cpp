#include <Arduino.h>
#include <ESP32Servo.h>
#include "servo.h"

Servo myServo;

void servo_setup(){
    myServo.attach(13);
    Serial.println("Servo Station 1 Ready");
}

void drop_ball(){

    myServo.write(160); // Close
    delay(2000);

    myServo.write(180); // Open
    delay(250);

    myServo.write(105); // Drop Ball
    delay(2000);

}