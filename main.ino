
// BUILT-IN LIBRARIES
#include "Arduino.h"
#include "Wire.h"
#include "Servo.h"
#include <SoftwareSerial.h>

// CUSTOM LIBRARIES
#include "libraries/temperature/TH02_dev.cpp" // Temperature sensor library
#include "libraries/light/light.cpp" // Light sensor library

#include "libraries/clock/RTClib.cpp"

#define SERVO_PIN 9

// Bluetooth MAC ADDRESS
// E9:C4:C1:D2:5D:CA
#define RxD 10
#define TxD 11
SoftwareSerial BT(RxD, TxD);

// Servo servo;
int servoPosition = 0;
Servo servo;

LightSensor light(A2);

RTC_DS1307 rtc;
char daysOfTheWeek[7][12] = {
  "Sunday",
  "Monday",
  "Tuesday",
  "Wednesday",
  "Thursday",
  "Friday",
  "Saturday"
};

void setup() {

  Serial.begin(57600);

  // Temperature sensor
  delay(150);
  TH02.begin();
  delay(100);

  // Setup Bluetooth
  BT.flush();
  delay(500);
  BT.begin(57600);

  // Clock
  if (!rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
  }

  if (!rtc.isrunning()) {
    Serial.println("RTC is NOT running!");
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }

  // Servo
  servo.attach(SERVO_PIN);

}

void loop() {
  // DateTime now = rtc.now();

  // Serial.println("-------------------------");
  // Serial.println(now.minute(), DEC);
  // Serial.println(light.ReadLight());
  // Serial.println(TH02.ReadTemperature());
  // Serial.println(TH02.ReadHumidity());

  // servo.write(160);
  // delay(1000);
  // servo.write(0);
  // delay(1000);

  if (BT.available() > 0) {

    char value = BT.read();
    BT.flush();

    if (value == 'e') {
      servo.write(160);
    }

    if (value == 'a') {
      servo.write(0);
    }

    Serial.println (value);
  }

  delay(100);
}
