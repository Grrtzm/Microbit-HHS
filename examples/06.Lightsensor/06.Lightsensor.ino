/*
  Arduino "AnalogReadSerial" omgebouwd naar lichtsensor.
  Meet de lichtsterkte op de middelste led in het 5x5 led display en toont dit in de
  plotter (druk Ctrl+Shift+L). 

  Reads an analog input on pin 0, prints the result to the Serial Monitor.
  Graphical representation is available using Serial Plotter (Tools > Serial Plotter menu).
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/AnalogReadSerial
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
  //Serial.println(gemiddelde); // met gemiddelde
  Serial.println(sensorValue); // zonder gemiddelde
  delay(10);        // delay in between reads for stability
}
