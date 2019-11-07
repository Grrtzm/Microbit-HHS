/*  Microbit Fade
 *  De Microbit heeft een 5x5 led display.
 *  Met dit programma wordt de led linksboven geleidelijk aan- en uitgezet.
 *  Zie http://www.arduino.cc/en/Tutorial/Fade
 *  
 *  Gert den Neijsel, Haagse Hogeschool, okt-2019
 *  Gebaseerd op Arduino Fade voorbeeldcode.
 *  This example code is in the public domain.
 */

const int COL1 = 3;   // Column #1 control
const int LED = 26;   // 'row 1' led
int brightness = 0;    // how bright the LED is
int fadeAmount = 5;    // how many points to fade the LED by

// the setup routine runs once when you press reset:
void setup() {
   // because the LEDs are multiplexed, we must ground the opposite side of the LED
  pinMode(COL1, OUTPUT);
  digitalWrite(COL1, LOW);
  pinMode(LED, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  // set the brightness of pin 9:
  analogWrite(LED, brightness);

  // change the brightness for next time through the loop:
  brightness = brightness + fadeAmount;

  // reverse the direction of the fading at the ends of the fade:
  if (brightness <= 0 || brightness >= 255) {
    fadeAmount = -fadeAmount;
  }
  // wait for 30 milliseconds to see the dimming effect
  delay(30);
}
