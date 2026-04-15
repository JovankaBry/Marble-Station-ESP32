#include <Arduino.h>
#include <ESP32Servo.h>
#include "servo.h"

Servo servo1;
Servo servo2;
Servo servo3;

// Servo setup
void setupServo() {
    servo1.attach(12); // Attach the servo to GPIO pin 12
    servo2.attach(13); // Attach the servo to GPIO pin 14
    servo3.attach(14); // Attach the servo to GPIO pin 27

    Serial.println("Servos Ready!");
}

void servo_1(){
    servo1.write(180);
    delay(500);
    servo1.write(90);
    delay(500);
}

void servo_2(){
    servo2.write(140);
    delay(500);
    servo2.write(50);
    delay(500);
}

void servo_3(){
    servo3.write(140);
    delay(500);    
    servo3.write(50);
    delay(500);
}