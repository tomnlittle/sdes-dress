
#include "Arduino.h"
#include "Wire.h"

// #include "Servo.h"
// #include "libraries/temperature/TH02_dev.cpp" // Temperature sensor library
#include "libraries/light/light.cpp" // Light sensor library
// #include "libraries/clock/clock.cpp" // Clock sensor library

// Servo servo;
// int servoPosition = 0;

LightSensor light(A10);
// Clock clock;

// float readTemperature() {
//   return TH02.ReadTemperature();
// }

// float readHumidity() {
//   return TH02.ReadHumidity();
// }

// void setupTemperature() {
//   /* Power up,delay 150ms,until voltage is stable */
//   delay(150);

//   /* Reset HP20x_dev */
//   TH02.begin();
//   delay(100);
// }

void setup() {
  // attach the main servo
  // servo.attach(10);
  // setupTemperature();
}

void loop() {
  Serial.println(light.ReadLight());
  // servo.UpdateLocation(180);
  //  for (pos = 0; pos <= 270; pos += 1) { // goes from 0 degrees to 180 degrees
  //   servo.write(pos);              // tell servo to go to position in variable 'pos'
  //   delay(15);                       // waits 15ms for the servo to reach the position
  // }
  // for (pos = 270; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
  //   servo.write(pos);              // tell servo to go to position in variable 'pos'
  //   delay(15);                       // waits 15ms for the servo to reach the position
  // }

  // Serial.println("Hello World");
}
