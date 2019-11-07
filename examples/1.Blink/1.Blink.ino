/* Microbit Blink
 *  Het allereerste en eenvoudigste voorbeeld wat bij elke microcontroller gebruikt wordt.
 *  De Microbit heeft een 5x5 led display.
 *  Met dit programma wordt de led linksboven 1x per seconde aan- en uitgezet.
 *  Zie http://www.arduino.cc/en/Tutorial/Blink
 *  
 *  Gert den Neijsel, Haagse Hogeschool, okt-2019
 *  Gebaseerd op Arduino Blink voorbeeldcode.
 *  This example code is in the public domain.
 */

const int COL1 = 3;   // Column #1 control
const int LED = 26;   // 'row 1' led

void setup() {
  Serial.begin(9600);
  Serial.println("microbit is ready!");

  // because the LEDs are multiplexed, we must ground the opposite side of the LED
  pinMode(COL1, OUTPUT);
  digitalWrite(COL1, LOW);
  pinMode(LED, OUTPUT);
}

void loop() {
  Serial.println("blink!");
  digitalWrite(LED, HIGH);
  delay(500);
  digitalWrite(LED, LOW);
  delay(500);
}
