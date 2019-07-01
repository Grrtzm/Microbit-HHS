
/*
   Serial Port over BLE
   Create UART service compatible with Nordic's *nRF Toolbox* and Adafruit's *Bluefruit LE* iOS/Android apps.

   Copyright (c) Sandeep Mistry. All rights reserved.
   Licensed under the MIT license. See LICENSE file in the project root for full license information.
   BLESerial class implements same protocols as Arduino's built-in Serial class and can be used as it's wireless
   replacement. Data transfers are routed through a BLE service with TX and RX characteristics. To make the
   service discoverable all UUIDs are NUS (Nordic UART Service) compatible.

   Please note that TX and RX characteristics use Notify and WriteWithoutResponse, so there's no guarantee
   that the data will make it to the other end. However, under normal circumstances and reasonable signal
   strengths everything works well.

   20190601 Uitbreiding Gert: Via seriel en Bluetooth verzonden karakters worden om matrix display weergegeven.
   Vergelijk de code uit dit programma met dat uit ble_uartdemo (het origineel).

   Original file: ble_uartdemo from https://github.com/adafruit/Adafruit_Microbit
*/

#include <Adafruit_Microbit.h>

Adafruit_Microbit microbit;

void setup() {
  Serial.begin(115200);

  Serial.println("Microbit ready!");

  // custom services and characteristics can be added as well
  microbit.BTLESerial.begin();
  microbit.BTLESerial.setLocalName("microbit");

  // Start LED matrix driver after radio (required)
  microbit.begin();
}

void loop() {
  microbit.BTLESerial.poll();

  /* Gert 20190601: Zo kun je het matrix display samen met Bluetooth gebruiken:
    microbit.matrix.show(microbit.matrix.HEART);
    // Zie voorbeeld "matrixdemo". Normaal zou hier staan:
    microbit.show(microbit.HEART);
    delay(100);
    microbit.matrix.clear();
    delay(100);
  */

  forward();
  //loopback();
  spam();
}


// forward received from Serial to microbit.BTLESerial and vice versa
void forward() {
  if (microbit.BTLESerial && Serial) {
    char buffer[10];

    if (microbit.BTLESerial.available()) {
      uint8_t byte = microbit.BTLESerial.read();
      Serial.write(byte);
      String str = String((char)byte); // omzetten van int naar char naar String
      str.toCharArray(buffer, 2); // String omzetten naar c-string
      microbit.matrix.print(buffer); // druk het karakter dat via Bluetooth is ontvangen af op het matrix display
    }

    memset(buffer, 0x0, 10); // buffer weer leeg maken (vullen met nullen)
    int idx = 0;
    while (Serial.available() && idx != 10) {
      buffer[idx] = Serial.read();
      idx++;
    }
    if (idx) {
      microbit.BTLESerial.write(buffer, idx);
      microbit.matrix.scrollText(buffer); // schrijf de tekst die van de seriële poort ontvangen is naar matrix display
    }
  }
  delay(1);
}

// echo all received data back
void loopback() {
  if (microbit.BTLESerial) {
    int byte;
    while ((byte = microbit.BTLESerial.read()) > 0) {
      microbit.BTLESerial.write(byte);
    }
  }
}

// periodically sent time stamps
void spam() {
  if (microbit.BTLESerial) {
    microbit.BTLESerial.print(millis());
    microbit.BTLESerial.println(" tick-tacks!");
    delay(1000);
    microbit.matrix.clear(); // hier neergezet om (in 'forward()') via Bluetooth verzonden- en weergegeven karakters weer te wissen
  }
}
