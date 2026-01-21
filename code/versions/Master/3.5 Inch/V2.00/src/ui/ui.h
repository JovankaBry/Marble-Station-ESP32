#pragma once
#include <Arduino.h>

void ui_init();
void draw_string(const char *string, int32_t x, int32_t y, uint8_t font);
void draw_rect(int32_t x,int32_t y, int32_t w, int32_t h, uint32_t color, uint8_t thickness);