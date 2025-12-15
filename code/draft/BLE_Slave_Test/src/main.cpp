#include <Arduino.h>
#include "BluetoothSerial.h"

BluetoothSerial SerialBT;

void setup() {
  Serial.begin(115200);

  SerialBT.begin("MarbleSlave", true); // true = client mode
  Serial.println("BT client started");

  // Connect to master by name
  if (SerialBT.connect("MarbleMaster")) {
    Serial.println("Connected to MarbleMaster ✅");
  } else {
    Serial.println("Connect failed ❌");
  }
}

void loop() {
  if (SerialBT.connected() && SerialBT.available()) {
    uint8_t page = SerialBT.read();
    Serial.print("Current page = ");
    Serial.println(page);

    // TODO: use it (switch-case, etc.)
  }
  delay(20);
}