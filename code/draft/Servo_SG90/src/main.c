#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "servo_driver.h"
#include "esp_log.h"

#define SERVO_PIN 25
#define TAG "MAIN"

void app_main(void)
{
    ESP_LOGI(TAG, "Starting servo demo...");
    servo_init(SERVO_PIN);

    while(1){
    float angle = 0.0f;
    servo_set_angle(angle);
    vTaskDelay(pdMS_TO_TICKS(1500));

    angle = 180.0f;
    servo_set_angle(angle);
    vTaskDelay(pdMS_TO_TICKS(1500));
    }
}
