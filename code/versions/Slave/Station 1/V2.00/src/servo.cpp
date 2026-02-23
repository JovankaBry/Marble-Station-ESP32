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
        myServo.write(40);
        delay(150);
        myServo.write(180);
        delay(150);
    }
}

void drop_ball(){

    myServo.write(160); // Close
    delay(2000);

    myServo.write(180); // Open
    delay(250);

    myServo.write(105); // Drop Ball
    delay(2000);

}

