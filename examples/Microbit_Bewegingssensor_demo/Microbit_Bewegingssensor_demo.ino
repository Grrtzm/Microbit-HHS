/**
 ******************************************************************************
 * Microbit Bewegingssensor demo (LSM303AGR)
 * Deze versie: Gert den Neijsel, Haagse Hogeschool, okt-2019
 * Gebruik deze met de Seriële Monitor (Ctrl+Shift+M) 
 * of met de Seriële Plotter (Ctrl+Shift+L)
 ******************************************************************************
 * @file    X_NUCLEO_IKS01A2_LSM303AGR_DataLog_Terminal.ino
 * @author  AST
 * @version V1.0.0
 * @date    7 September 2017
 * @brief   Arduino test application for the STMicrolectronics X-NUCLEO-IKS01A2
 *          MEMS Inertial and Environmental sensor expansion board.
 *          This application makes use of C++ classes obtained from the C
 *          components' drivers.
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; COPYRIGHT(c) 2017 STMicroelectronics</center></h2>
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *   1. Redistributions of source code must retain the above copyright notice,
 *      this list of conditions and the following disclaimer.
 *   2. Redistributions in binary form must reproduce the above copyright notice,
 *      this list of conditions and the following disclaimer in the documentation
 *      and/or other materials provided with the distribution.
 *   3. Neither the name of STMicroelectronics nor the names of its contributors
 *      may be used to endorse or promote products derived from this software
 *      without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 ******************************************************************************
 */

#include <LSM303AGR_ACC_Sensor.h>
#include <LSM303AGR_MAG_Sensor.h>

LSM303AGR_ACC_Sensor *Acc;
LSM303AGR_MAG_Sensor *Mag;

const int COL1 = 3;   // Column #1 control
const int LED = 26;   // 'row 1' led

void setup() {
  // because the LEDs are multiplexed, we must ground the opposite side of the LED
  pinMode(COL1, OUTPUT);
  digitalWrite(COL1, LOW);
  pinMode(LED, OUTPUT);

  // Initialize serial for output.
  Serial.begin(9600);
  Serial.println("Microbit Bewegingssensor demo (LSM303AGR)");
  
  // Initialize I2C bus.
  Wire.begin();

  // Initlialize components.
  Acc = new LSM303AGR_ACC_Sensor(&Wire);
  Acc->Enable();
  Mag = new LSM303AGR_MAG_Sensor(&Wire);
  Mag->Enable();
}

void loop() {
  // Led laten knipperen als teken dat het programma loopt (Zie 1.Blink voorbeeldcode).
  digitalWrite(LED, HIGH);
  delay(250);
  digitalWrite(LED, LOW);
  delay(250);

  // Read accelerometer LSM303AGR.
  int32_t accelerometer[3]; // De vierkante haakjes wijzen op een Array. Zie https://www.arduino.cc/en/Tutorial/Arrays
  Acc->GetAxes(accelerometer);
  
  // Read magnetometer LSM303AGR.
  int32_t magnetometer[3];
  Mag->GetAxes(magnetometer);

  // Output data.
  Serial.print("| Acc[mg]: ");
  Serial.print(accelerometer[0]); 
  Serial.print(" ");
  Serial.print(accelerometer[1]);
  Serial.print(" ");
  Serial.print(accelerometer[2]);
  Serial.print(" | Mag[mGauss]: ");
  Serial.print(magnetometer[0]);
  Serial.print(" ");
  Serial.print(magnetometer[1]);
  Serial.print(" ");
  Serial.print(magnetometer[2]);
  Serial.println(" |");
}