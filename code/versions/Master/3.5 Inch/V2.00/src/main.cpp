#include <Arduino.h>
#include <TFT_eSPI.h>
#include "ui/ui.h"
#include "ble/ble.h"
#include "encoder/encoder.h"
#include "page/containers.h"
#include "app/app.h"

void setup(){
  Serial.begin(115200);
  app_setup();
  //ble_setup();
}

void loop(){
  app_loop();
}