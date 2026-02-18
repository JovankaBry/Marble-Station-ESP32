#include <Arduino.h>
#include <ESP32Servo.h>
#include "servo.h"

Servo myServo;

void servo_setup(){
    myServo.attach(13);
    Serial.println("Servo Ready");
}

void anti_clog(){
    for(int i=0 ; i < 7 ; i++){
        myServo.write(60);
        delay(150);
        myServo.write(180);
        delay(150);
    }
}

void drop_ball(){

    myServo.write(60); // Close
    delay(2000);

    myServo.write(40); // Open
    delay(500);
    
    myServo.write(140);
    delay(300);

    myServo.write(70);
    delay(200);

    myServo.write(110);
    delay(3000);

    anti_clog();
}

