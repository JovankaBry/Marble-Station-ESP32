#include <Arduino.h>
#include "BluetoothSerial.h"

BluetoothSerial SerialBT;

const char* BT_NAME = "ESP32_SLAVE";

uint32_t lastPrint = 0;

void setup() {
  Serial.begin(115200);
  delay(500);

  if (!SerialBT.begin(BT_NAME)) {
    Serial.println("BT start failed!");
    while (1) delay(1000);
  }

  Serial.println("Slave ready. Pair/connect to: ESP32_SLAVE");
}

void loop() {
  // If something received over BT, read it and reply
  if (SerialBT.available()) {
    String msg = SerialBT.readStringUntil('\n');  // expects newline from master
    msg.trim();

    Serial.print("RX: ");
    Serial.println(msg);

    // Reply
    SerialBT.print("ACK ");
    SerialBT.println(msg);
  }
}