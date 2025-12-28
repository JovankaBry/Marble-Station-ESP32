#include <Arduino.h>
#include "BluetoothSerial.h"

BluetoothSerial SerialBT;

const char* SLAVE_NAME = "ESP32_SLAVE";

uint32_t lastSend = 0;
uint32_t counter = 0;

void setup() {
  Serial.begin(115200);
  delay(500);

  // IMPORTANT: master mode = true
  if (!SerialBT.begin("ESP32_MASTER", true)) {
    Serial.println("BT begin failed!");
    while (1) delay(1000);
  }

  Serial.println("Master starting...");
  Serial.print("Connecting to "); Serial.println(SLAVE_NAME);

  while (!SerialBT.connect(SLAVE_NAME)) {
    Serial.println("Connect failed, retrying...");
    delay(1000);
  }

  Serial.println("Connected!");
}

void loop() {
  if (millis() - lastSend >= 200) {
    lastSend = millis();
    counter++;

    SerialBT.print("PING ");
    SerialBT.println(counter);

    Serial.print("TX: PING ");
    Serial.println(counter);
  }

  if (SerialBT.available()) {
    String msg = SerialBT.readStringUntil('\n');
    msg.trim();
    Serial.print("RX: ");
    Serial.println(msg);
  }
}