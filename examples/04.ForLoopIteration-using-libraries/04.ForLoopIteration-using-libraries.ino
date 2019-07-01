/*  De 'ForLoopIteration' ("Night Rider" looplicht) van Arduino, omgebouwd naar Microbit
 *  zie http://www.arduino.cc/en/Tutorial/ForLoop
 *  maar nu (om het makkelijker te maken) met gebruik van de Adafruit Microbit library.
*/
#include <Adafruit_Microbit.h>

Adafruit_Microbit_Matrix microbit;

int timer = 100;           // The higher the number, the slower the timing.

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
    microbit.drawPixel(x, 2, LED_ON); // 2 is middle row of leds
    delay(timer);
    // turn the led off:
    microbit.drawPixel(x, 2, LED_OFF);
  }

  // loop from the leftmost led to the rightmost:
  for (int x = 4; x >= 0; x--) {
    // turn the led on:
    microbit.drawPixel(x, 2, LED_ON); // 2 is middle row of leds
    delay(timer);
    // turn the led off:
    microbit.drawPixel(x, 2, LED_OFF);
  }

}
