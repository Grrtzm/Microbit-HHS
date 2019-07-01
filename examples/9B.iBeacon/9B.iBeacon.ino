// Copyright (c) Sandeep Mistry. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

// More info: https://en.wikipedia.org/wiki/IBeacon
// Android app to use: iBeacon & Eddystone Scanner, see https://flurp.de/apps 

#include <BLEPeripheral.h>
#include <iBeacon.h>

iBeacon beacon;

void setup() {
  char* uuid                   = "a196c876-de8c-4c47-ab5a-d7afd5ae7127";
  unsigned short major         = 0;
  unsigned short minor         = 0;
  unsigned short measuredPower = -55;

  beacon.begin(uuid, major, minor, measuredPower);
}

void loop() {
  beacon.loop();
}
