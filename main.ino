
// BUILT-IN LIBRARIES
#include "Arduino.h"
#include "Wire.h"
#include "Servo.h"

// CUSTOM LIBRARIES
#include "libraries/temperature/TH02_dev.cpp"
#include "libraries/clock/RTClib.cpp"

#define SERVO_PIN 9

// Servo servo;
int servoPosition = 0;
Servo servo;

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

  // Activate the built-in LED
  pinMode(LED_BUILTIN, OUTPUT);

}

bool systemStatus(DateTime now) {
  bool timeCheck = now.minute() != 165;   // 165 is a time error
  bool tempCheck = TH02.ReadTemperature() > 20 && TH02.ReadTemperature() < 80;

  return timeCheck && tempCheck;
}

void loop() {
  DateTime now = rtc.now();

  if (systemStatus(now)) {
    digitalWrite(LED_BUILTIN, HIGH);
  } else {
    digitalWrite(LED_BUILTIN, LOW);
  }

  Serial.println("-------------------------");
  Serial.print(now.hour(), DEC);
  Serial.print(":");
  Serial.println(now.minute(), DEC);

  Serial.println(TH02.ReadTemperature());
  Serial.println(TH02.ReadHumidity());

  // servo.write(360);
  // delay(1000);
  // servo.write(0);
  // delay(1000);
}
