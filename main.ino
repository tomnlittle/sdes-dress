// BUILT-IN LIBRARIES
#include "Arduino.h"
#include "Wire.h"
// #include "Servo.h"

// CUSTOM LIBRARIES
#include "libraries/temperature/TH02_dev.cpp" // Temperature sensor library
#include "libraries/light/light.cpp" // Light sensor library
// #include "libraries/clock/clock.cpp" // Clock sensor library

// Servo servo;
// int servoPosition = 0;

LightSensor light(A10);
// Clock clock;

void isAlive() {
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(100);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(100);
}

void setup() {
  Serial.begin(9600);

  // Setup the builtin led
  pinMode(LED_BUILTIN, OUTPUT);

  // attach the main servo
  // servo.attach(10);

  /* Power up,delay 150ms,until voltage is stable */
  delay(150);

  /* Reset HP20x_dev */
  TH02.begin();
  delay(100);
}

void loop() {

  isAlive();
  Serial.println(".");
  Serial.println(light.ReadLight());
  Serial.println(TH02.ReadTemperature());
  // Serial.println(TH02.ReadHumidity());


  // clock.printTime();
}

  // servo.UpdateLocation(180);
  //  for (pos = 0; pos <= 270; pos += 1) { // goes from 0 degrees to 180 degrees
  //   servo.write(pos);              // tell servo to go to position in variable 'pos'
  //   delay(15);                       // waits 15ms for the servo to reach the position
  // }
  // for (pos = 270; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
  //   servo.write(pos);              // tell servo to go to position in variable 'pos'
  //   delay(15);                       // waits 15ms for the servo to reach the position
  // }
