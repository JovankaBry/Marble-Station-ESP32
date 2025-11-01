#ifndef SERVO_DRIVER_H
#define SERVO_DRIVER_H

#include "driver/ledc.h"
#include "esp_err.h"

// Public functions
void servo_init(int gpio);
void servo_set_angle(float angle);

#endif