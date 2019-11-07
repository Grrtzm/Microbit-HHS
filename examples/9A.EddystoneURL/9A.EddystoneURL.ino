// Copyright (c) Sandeep Mistry. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

// More info: https://en.wikipedia.org/wiki/Eddystone_(Google)
//            https://developer.estimote.com/eddystone/
// Android app to use: iBeacon & Eddystone Scanner, see https://flurp.de/apps 

// Import libraries (EddystoneBeacon depends on SPI)
#include <SPI.h>
#include <EddystoneBeacon.h>

EddystoneBeacon eddystoneBeacon = EddystoneBeacon(BLE_DEFAULT_REQ, BLE_DEFAULT_RDY, BLE_DEFAULT_RST);

void setup() {
  Serial.begin(9600);

  delay(1000);

  eddystoneBeacon.begin(-18, "https://svequinox.nl"); // power, URI

  Serial.println(F("Eddystone URL Beacon"));
}

void loop() {
  eddystoneBeacon.loop();
}
