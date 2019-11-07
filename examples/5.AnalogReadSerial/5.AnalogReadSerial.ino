/*
 * Arduino "AnalogReadSerial" omgebouwd naar Microbit versie.
 *  
 * Leest een analoge ingang op pin 0 en stuurt het resultaat naar de Seriële Monitor (Ctrl+Shift+M).
 * Een grafische weergave is beschikbaar via de Seriële Plotter (Ctrl+Shift+L).
 *  
 * Gert den Neijsel, Haagse Hogeschool, okt-2019
 * Gebaseerd op Arduino AnalogReadSerial voorbeeldcode.
 * http://www.arduino.cc/en/Tutorial/AnalogReadSerial
 * This example code is in the public domain.
 */


// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  // pinMode(0, INPUT_PULLUP); // interne pull up weerstand voor pin 0 aanzetten
}

// the loop routine runs over and over again forever:
void loop() {
  int sensorValue = analogRead(0); // Raak het gouden vlakje '0' aan en kijk wat er gebeurt in de Seriële Plotter (Ctrl+Shift+L)
  Serial.println(sensorValue);
  delay(10);        // delay in between reads for stability
}
