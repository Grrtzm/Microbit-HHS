/*
  Arduino "AnalogReadSerial" omgebouwd naar Microbit versie.

  Reads an analog input on pin 0, prints the result to the Serial Monitor.
  Graphical representation is available using Serial Plotter (Tools > Serial Plotter menu).
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/AnalogReadSerial
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
