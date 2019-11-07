/* Microbit Lichtsterkte meten
 *  De Microbit heeft een 5x5 led display.
 *  Met dit programma wordt de lichtsterkte gemeten met de middelste led.
 *  
 *  Gebruik de Serial Plotter (Ctrl+Shift+L) om een grafiek weer te geven.
 *  Probeer het eens met- en zonder gemiddelde (comments verwijderen van 2 na onderste regel).
 *  
 *  Gert den Neijsel, Haagse Hogeschool, okt-2019
 *  Gebaseerd op Arduino AnalogReadSerial voorbeeldcode.
 *  Zie http://www.arduino.cc/en/Tutorial/AnalogReadSerial
 *  This example code is in the public domain.
 */

const int LED = 27;   // 'row 2' led
const int COL = 10;   // 'col 2' led
const int arrayGrootte = 50; // hoe groter het array hoe gelijkmatiger, maar wel trager
int waardes[arrayGrootte]; // array met bovenstaande grootte declareren

// Functie gemiddelde() - array vullen met de laatste 'arrayGrootte' aantal waardes en daar het gemiddelde van bepalen.
int berekenGemiddelde(int waarde) {
  int som = waarde;
  waardes[0] = waarde;
  for (int n = arrayGrootte - 1; n > 0; n--) { // teller van hoog naar laag
    // oude waardes doorschuiven in het array, bovenaan beginnen:
    waardes[n] = waardes[n - 1];
    som = som + waardes[n]; // huidige waarde bij de som optellen
  }
  return som / arrayGrootte; // het resultaat (het gemiddelde) teruggeven
}

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW);
}

// the loop routine runs over and over again forever:
void loop() {
  // lees de lichtwaarde op de middelste led (row2 / col2).
  // Let op: als je het middelste gouden contact tussen vlakje '1' en '2' aanraakt (pin 10) meet je ook een waarde. Dit is aanraking, geen licht!
  int sensorValue = analogRead(COL); // let op: weinig licht geeft hogere waarde, veel licht geeft lage waarde
  int gemiddelde = berekenGemiddelde(sensorValue);
  // print out the value you read:
  //Serial.println(gemiddelde); // met gemiddelde, dus trager
  Serial.println(sensorValue); // zonder gemiddelde, dus snel
  delay(10);        // delay in between reads for stability
}
