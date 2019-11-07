/* Microbit for loop iteration
 *  De Microbit heeft een 5x5 led display.
 *  Met dit programma worden alle leds van linksboven tot rechtsonder even aangezet.
 *  Zie https://www.arduino.cc/en/Tutorial/Arrays
 *  en https://www.arduino.cc/en/Tutorial/ForLoopIteration
 *  
 *  Gert den Neijsel, Haagse Hogeschool, okt-2019
 *  Gebaseerd op Arduino ForLoopIteration voorbeeldcode.
 *  This example code is in the public domain.
 */
 
// Array groottes definiëren
#define MATRIX_ROWS 3   
#define MATRIX_COLS 9
uint8_t rowpins[MATRIX_ROWS] = {26, 27, 28}; // hoog maken om led te laten branden
uint8_t colpins[MATRIX_COLS] = {3, 4, 10, 23, 24, 25, 9, 7, 6}; // laag maken om led te laten branden

// Array met indeling van het 5x5 led display (rijen)
uint8_t pixel_to_row[25] = {1, 2, 1, 2, 1,
                            3, 3, 3, 3, 3,
                            2, 1, 2, 3, 2,
                            1, 1, 1, 1, 1,
                            3, 2, 3, 2, 3
                           };

// Array met indeling van het 5x5 led display (kolommen)
uint8_t pixel_to_col[25] = {1, 4, 2, 5, 3,
                            4, 5, 6, 7, 8,
                            2, 9, 3, 9, 1,
                            8, 7, 6, 5, 4,
                            3, 7, 1, 6, 2
                           };

void setup() {
  Serial.begin(9600);
  Serial.println("Microbit is ready!");

  // Eerst alle leds uitzetten:
  Serial.print("Row pin: ");
  for (uint8_t n = 0; n < MATRIX_ROWS; n++) {
    Serial.print(rowpins[n]);
    Serial.print(", ");
    pinMode(rowpins[n], OUTPUT);
    digitalWrite(rowpins[n], LOW); // laag maken om alle leds uit te zetten
  }
  Serial.println();
  Serial.print("Col pin: ");
  for (uint8_t n = 0; n < MATRIX_COLS; n++) {
    Serial.print(colpins[n]);
    Serial.print(", ");
    pinMode(colpins[n], OUTPUT);
    digitalWrite(colpins[n], HIGH); // hoog maken om alle leds uit te zetten
  }
  Serial.println();
  Serial.println();
}

void loop() {
  Serial.println("blink!");
  for (uint8_t n = 0; n < 25; n++) {
    Serial.print(n);
    Serial.print("\t");
    Serial.print(pixel_to_row[n]);
    Serial.print("\t");
    Serial.print(rowpins[pixel_to_row[n]-1]);
    Serial.print("\t");
    Serial.print(pixel_to_col[n]);
    Serial.print("\t");
    Serial.print(colpins[pixel_to_col[n]-1]);
    Serial.println();
    
    // Specifiek één led in de matrix aanzetten.
    digitalWrite(rowpins[pixel_to_row[n]-1], HIGH);
    digitalWrite(colpins[pixel_to_col[n]-1], LOW);
    delay(500);
    // Diezelfde led weer uitzetten.
    digitalWrite(rowpins[pixel_to_row[n]-1], LOW);
    digitalWrite(colpins[pixel_to_col[n]-1], HIGH);
  }
}
