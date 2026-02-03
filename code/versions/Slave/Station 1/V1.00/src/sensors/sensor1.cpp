#include <Arduino.h>
#include "sensor1.h"

#define SENSOR_DO 21

static int ballCount = 0;
static bool lastDetected = false;
static unsigned long lastMs = 0;
static const unsigned long COOLDOWN_MS = 150;

void sensor1_setup() {
    pinMode(SENSOR_DO, INPUT);
}

bool sensor1_update() {
    bool detected = (digitalRead(SENSOR_DO) == LOW); 
    bool newBall = false;

    if (detected && !lastDetected) {
        unsigned long now = millis();
        if (now - lastMs > COOLDOWN_MS) {
            ballCount++;
            lastMs = now;
            newBall = true;
        }
    }

    lastDetected = detected;
    return newBall; 
}

int sensor1_get_count() {
    return ballCount;
}