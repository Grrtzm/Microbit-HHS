/*  Dit programmaatje laat zien hoe je op de 5x5 led matrix 
 *  van de Microbit elke led individueel aanstuurt.
 *  Daarbij introduceert het arrays en de "for" loop.
  */
#define MATRIX_ROWS 3
#define MATRIX_COLS 9
uint8_t rowpins[MATRIX_ROWS] = {26, 27, 28}; // hoog maken om led te laten branden
uint8_t colpins[MATRIX_COLS] = {3, 4, 10, 23, 24, 25, 9, 7, 6}; // laag maken om led te laten branden

// Hieronder worden de arrays gedefinieerd 
uint8_t pixel_to_row[25] = {1, 2, 1, 2, 1,
                            3, 3, 3, 3, 3,
                            2, 1, 2, 3, 2,
                            1, 1, 1, 1, 1,
                            3, 2, 3, 2, 3
                           };

uint8_t pixel_to_col[25] = {1, 4, 2, 5, 3,
                            4, 5, 6, 7, 8,
                            2, 9, 3, 9, 1,
                            8, 7, 6, 5, 4,
                            3, 7, 1, 6, 2
                           };

void setup() {
  for (uint8_t n = 0; n < MATRIX_ROWS; n++) {
    pinMode(rowpins[n], OUTPUT);
    digitalWrite(rowpins[n], LOW); // laag maken om alle leds uit te zetten
  }
  // because the LEDs are multiplexed, we must ground the opposite side of the LED
  for (uint8_t n = 0; n < MATRIX_COLS; n++) {
    pinMode(colpins[n], OUTPUT);
    digitalWrite(colpins[n], HIGH); // hoog maken om alle leds uit te zetten
  }
}

void loop() {
  for (uint8_t n = 0; n < 25; n++) {
    digitalWrite(rowpins[pixel_to_row[n]-1], HIGH);
    digitalWrite(colpins[pixel_to_col[n]-1], LOW);
    delay(100); // de snelheid waarmee de leds knipperen
    digitalWrite(rowpins[pixel_to_row[n]-1], LOW);
    digitalWrite(colpins[pixel_to_col[n]-1], HIGH);
  }
}
