
/*
 Stepper Motor Control - one revolution

 This program drives a unipolar or bipolar stepper motor.
 The motor is attached to digital pins 8 - 11 of the Arduino.

 The motor should revolve one revolution in one direction, then
 one revolution in the other direction.


 Created 11 Mar. 2007
 Modified 30 Nov. 2009
 by Tom Igoe

 */
#include <TMCStepper.h>


#define dir  16
#define steP 17
#define RXD2 19
#define TXD2 21
#define DRIVER_ADDRESS   0b00

TMC2209Stepper driver(&Serial2, 0.11f , DRIVER_ADDRESS);

void setup() {
  Serial.begin(115200);
  Serial2.begin(115200, SERIAL_8N1, RXD2, TXD2);
  
  pinMode (dir, OUTPUT);
  pinMode (steP, OUTPUT);

  driver.begin();
  Serial.println(driver.version(), HEX);
  //driver.push();
  driver.GCONF(1);
  Serial.println(driver.GCONF(), HEX);
  
}

void loop() {
  digitalWrite(dir, HIGH);
  
  digitalWrite(steP, HIGH);
  delayMicroseconds(300);
  digitalWrite(steP, LOW);
  delayMicroseconds(300);

  
}
