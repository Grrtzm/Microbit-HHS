/* Microbit Buttons
 *  Met dit programma wordt de toestand van de knopjes uitgelezen.
 *  Gebruik de Serial Monitor (Ctrl + Shift + M) om de uitvoer weer te geven.
 *  
 *  Gert den Neijsel, Haagse Hogeschool, okt-2019
 *  Gebaseerd op Adafruit voorbeeldcode.
 *  This example code is in the public domain.
 */

const int buttonA = 5;   // het pinnummer van drukknop A
const int buttonB = 11;  // het pinnummer van drukknop B

void setup () {
  Serial.begin (9600);
  Serial.println ("Microbit is klaar!");
  pinMode (buttonA, INPUT);
  pinMode (buttonB, INPUT);
}

void loop () {
  if (! digitalRead (buttonA)) {
    Serial.println ("Knop A ingedrukt");
  }
  if (! digitalRead (buttonB)) {
    Serial.println ("Knop B ingedrukt");
  }
  delay (10);
}
