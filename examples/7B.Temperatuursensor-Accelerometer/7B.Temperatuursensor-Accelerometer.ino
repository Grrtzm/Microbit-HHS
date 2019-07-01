/* Dit programma leest de temperatuursensor in de Accelerometer chip uit.
  Afgeleid uit het voorbeeld en de code van de Sodaq Library
*/

#include <Sodaq_LSM303AGR.h>
#define OVERSAMPLE 500 // een gemiddelde over 500 metingen is wel heel veel hoor, maar anders is hij erg onnauwkeurig!

Sodaq_LSM303AGR accel;

void setup()
{
  Serial.begin(9600);
  Wire.begin();
  delay(1000);

  if (!accel.checkWhoAmI()) {
    Serial.println("NO ACCELOMETER FOUND!");
  }

  accel.rebootAccelerometer();
  delay(1000);

  accel.enableAccelerometer(Sodaq_LSM303AGR::NormalMode);
}

void loop()
{

  // Take 'OVERSAMPLES' measurements and average them!
  // We nemen een gemiddelde omdat de temperatuur op 0,25 graad wordt afgerond
  double avgtemp = 0;
  for (int i = 0; i < OVERSAMPLE; i++) {
    double temp;
    do {
      temp = accel.getTemperature();
    } while (temp == 0);  // re run until we get valid data
    avgtemp += temp;
    delay(1);
  }
  avgtemp /= OVERSAMPLE;

  //double temperatuur = accel.getTemperature();
  //Serial.println(temperatuur);

    //  Serial.print("Temperature (C): ");
  Serial.println(avgtemp);  // Double value since temp is in 0.25°C steps

  delay(1000);
}
