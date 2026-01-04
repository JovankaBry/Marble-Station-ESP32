#pragma once
#include <Arduino.h>

void encoderInit();
int  encoderStep();       // -1 / 0 / +1
bool encoderPressed();    // true once per press