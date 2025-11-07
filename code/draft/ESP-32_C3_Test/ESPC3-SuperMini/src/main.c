#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/ledc.h"
#include "esp_log.h"

#define TAG "SERVO"

#define SERVO_PIN   10                 // D10 on ESP32-C3 SuperMini
#define SERVO_FREQ  50                 // 50 Hz (20 ms period)
#define SERVO_MIN_US 1000              // ~0°
#define SERVO_MAX_US 2000              // ~180°

#define LEDC_MODE   LEDC_LOW_SPEED_MODE
#define LEDC_TIMER  LEDC_TIMER_0
#define LEDC_CH     LEDC_CHANNEL_0
#define LEDC_RES    LEDC_TIMER_14_BIT   // C3 supports up to 14-bit

static inline uint32_t us_to_duty(uint32_t us)
{
    const uint32_t period_us = 1000000UL / SERVO_FREQ;    // 20000 us
    const uint32_t max_duty  = (1U << LEDC_RES) - 1U;     // 16383 for 14-bit
    return (uint32_t)(((uint64_t)us * max_duty) / period_us);
}

static inline uint32_t angle_to_duty(float angle_deg)
{
    if (angle_deg < 0)   angle_deg = 0;
    if (angle_deg > 180) angle_deg = 180;
    uint32_t us = SERVO_MIN_US + (uint32_t)((angle_deg / 180.0f) * (SERVO_MAX_US - SERVO_MIN_US));
    return us_to_duty(us);
}

void app_main(void)
{
    ESP_LOGI(TAG, "Init LEDC for servo…");

    ledc_timer_config_t tcfg = {
        .speed_mode      = LEDC_MODE,
        .timer_num       = LEDC_TIMER,
        .duty_resolution = LEDC_RES,
        .freq_hz         = SERVO_FREQ,
        .clk_cfg         = LEDC_AUTO_CLK
    };
    ledc_timer_config(&tcfg);

    ledc_channel_config_t c = {
        .gpio_num   = SERVO_PIN,
        .speed_mode = LEDC_MODE,
        .channel    = LEDC_CH,
        .timer_sel  = LEDC_TIMER,
        .duty       = 0,
        .hpoint     = 0
    };
    ledc_channel_config(&c);

    while (1) {
        for (int a = 0; a <= 180; a += 10) {
            ledc_set_duty(LEDC_MODE, LEDC_CH, angle_to_duty(a));
            ledc_update_duty(LEDC_MODE, LEDC_CH);
            vTaskDelay(pdMS_TO_TICKS(200));
        }
        for (int a = 180; a >= 0; a -= 10) {
            ledc_set_duty(LEDC_MODE, LEDC_CH, angle_to_duty(a));
            ledc_update_duty(LEDC_MODE, LEDC_CH);
            vTaskDelay(pdMS_TO_TICKS(200));
        }
    }
}