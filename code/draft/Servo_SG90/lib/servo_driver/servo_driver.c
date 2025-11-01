#include "servo_driver.h"
#include "esp_log.h"

#define TAG "SERVO_DRIVER"

#define SERVO_TIMER LEDC_TIMER_0
#define SERVO_MODE LEDC_LOW_SPEED_MODE
#define SERVO_CHANNEL LEDC_CHANNEL_0
#define SERVO_FREQ 50
#define SERVO_RES LEDC_TIMER_16_BIT

static uint32_t max_duty = 0;   // stored after init

// Helper: convert angle (0–180°) to duty value
static uint32_t angle_to_duty(float angle)
{
    float pulse_us = 500.0f + (angle / 180.0f) * 2000.0f; // 0.5–2.5 ms pulse
    float duty_ratio = pulse_us / 20000.0f;               // 20 ms period (50 Hz)
    return (uint32_t)(duty_ratio * max_duty);
}

void servo_init(int gpio)
{
    ESP_LOGI(TAG, "Initializing servo on GPIO %d", gpio);

    ledc_timer_config_t timer_conf = {
        .speed_mode       = SERVO_MODE,
        .timer_num        = SERVO_TIMER,
        .duty_resolution  = SERVO_RES,
        .freq_hz          = SERVO_FREQ,
        .clk_cfg          = LEDC_AUTO_CLK
    };
    ledc_timer_config(&timer_conf);

    ledc_channel_config_t ch_conf = {
        .gpio_num       = gpio,
        .speed_mode     = SERVO_MODE,
        .channel        = SERVO_CHANNEL,
        .timer_sel      = SERVO_TIMER,
        .duty           = 0,
        .hpoint         = 0
    };
    ledc_channel_config(&ch_conf);

    max_duty = (1 << SERVO_RES) - 1;
}

void servo_set_angle(float angle)
{
    uint32_t duty = angle_to_duty(angle);
    ledc_set_duty(SERVO_MODE, SERVO_CHANNEL, duty);
    ledc_update_duty(SERVO_MODE, SERVO_CHANNEL);
    ESP_LOGI(TAG, "Angle %.0f° -> duty %lu", angle, duty);
}
