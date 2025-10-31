#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"

#define LED GPIO_NUM_2

void app_main(void){
    gpio_set_direction(LED,GPIO_MODE_OUTPUT);
    while (1){
        gpio_set_level(LED,1);
        vTaskDelay(pdMS_TO_TICKS(100));
        gpio_set_level(LED,0);
        vTaskDelay(pdMS_TO_TICKS(100));
    }
}