#include <Arduino.h>
#include <ESP32Servo.h>
#include "servo.h"

Servo myServo;

void servo_setup(){
    myServo.attach(13);
    Serial.println("Servo Station 1 Ready");
}

void drop_red(){
    myServo.write(60);
    delay(3000);
}

void drop_green(){
    myServo.write(30);
    delay(3000);
}

void drop_blue(){
    myServo.write(0);
    delay(3000);
}

void drop_close(){
    myServo.write(90);
    delay(3000);
}

void drop_ball(){

    drop_close();
    drop_red();
    drop_green();
    drop_blue();

}