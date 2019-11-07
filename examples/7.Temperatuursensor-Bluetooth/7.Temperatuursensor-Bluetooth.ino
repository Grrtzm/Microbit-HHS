/* Microbit Bluetooth temperatuursensor
 * Dit programma leest de temperatuursensor in de Bluetooth chip uit.
 * "Slow die temperature reader for piping to Adafruit IO"
 * Originele bestandsnaam: ble_dietemp.ino (voorbeeld uit https://github.com/adafruit/Adafruit_Microbit)
 *  
 * Gert den Neijsel, Haagse Hogeschool, okt-2019
 * This example code is in the public domain.
 */


#include <Adafruit_Microbit.h>
#define OVERSAMPLE 500 // een gemiddelde over 500 metingen is wel heel veel hoor, maar anders is hij erg onnauwkeurig!

Adafruit_Microbit microbit;

void setup()
{
  Serial.begin(9600);
  microbit.BTLESerial.begin();
  microbit.BTLESerial.setLocalName("microbit");

  // Start LED matrix driver after radio (required)
  microbit.begin();
}

void loop() {
  microbit.BTLESerial.poll();

  // Take 'OVERSAMPLES' measurements and average them!
  // We nemen een gemiddelde omdat de temperatuur in hele graden wordt gemeten.
  float avgtemp = 0;
  for (int i = 0; i < OVERSAMPLE; i++) {
    int32_t temp;
    do {
      temp = microbit.getDieTemp();
    } while (temp == 0);  // re run until we get valid data
    avgtemp += temp;
    delay(1);
  }
  avgtemp /= OVERSAMPLE;

  //  Serial.print("Temperature (C): ");
  Serial.println(avgtemp);  // Float value since temp is in 0.25°C steps

  // Send just the raw reading over bluetooth
  microbit.BTLESerial.println(avgtemp);

  delay(1000);
}
