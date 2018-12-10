
// BUILT-IN LIBRARIES
#include "Arduino.h"
#include "Wire.h"
// #include "Servo.h"

// CUSTOM LIBRARIES
#include "libraries/temperature/TH02_dev.cpp" // Temperature sensor library
#include "libraries/light/light.cpp" // Light sensor library

// #include "libraries/clock/DS1307.cpp"
// #include "libraries/clockj/RTClib.cpp"

// Servo servo;
// int servoPosition = 0;

LightSensor light(A10);

// Clock clock;
// DS1307 clock;

// RTC_DS1307 rtc;

// char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};


void setup() {
  // Temperature sensor
  delay(150);
  TH02.begin();
  delay(100);

  // Clock
  // if (!rtc.begin()) {
  //   Serial.println("Couldn't find RTC");
  //   while (1);
  // }

  // if (!rtc.isrunning()) {
  //   Serial.println("RTC is NOT running!");
  //   // rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  //   rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));
  // }
}

void loop() {
  // Serial.println(light.ReadLight());
  // Serial.println(TH02.ReadTemperature());
  // Serial.println(TH02.ReadHumidity());
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
