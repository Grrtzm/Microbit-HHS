/* Microbit for loop iteration
 *  Zie http://www.arduino.cc/en/Tutorial/ForLoop
 *  
 *  Gert den Neijsel, Haagse Hogeschool, okt-2019
 *  Gebaseerd op Arduino ForLoopIteration voorbeeldcode.
 *  This example code is in the public domain.
*/

#include <Adafruit_Microbit.h>

Adafruit_Microbit_Matrix microbit;

int timer = 100;    // The higher the number, the slower the timing.
int y = 2;          // 0 is top row, 2 is center row, 4 is bottom row of leds.

void setup() {
  // put your setup code here, to run once:
  microbit.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  microbit.clear();

  // loop from the leftmost led to the rightmost:
  for (int x = 0; x < 5; x++) {
    // turn the led on:
    microbit.drawPixel(x, y, LED_ON);
    delay(timer);
    // turn the led off:
    microbit.drawPixel(x, y, LED_OFF);
  }

  // loop from the leftmost led to the rightmost:
  for (int x = 4; x >= 0; x--) {
    // turn the led on:
    microbit.drawPixel(x, y, LED_ON);
    delay(timer);
    // turn the led off:
    microbit.drawPixel(x, y, LED_OFF);
  }

}
