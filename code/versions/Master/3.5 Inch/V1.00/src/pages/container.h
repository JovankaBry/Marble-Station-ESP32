#pragma once
#include <TFT_eSPI.h>

// enter container page (id = 1..4)
void container_enter(TFT_eSPI &tft, uint8_t containerId);

// update container page
// returns true if user wants to go back
bool container_update(TFT_eSPI &tft, int encStep, bool encPress);