
// BUILT-IN LIBRARIES
#include "Arduino.h"
#include "Wire.h"
#include "Servo.h"

// CUSTOM LIBRARIES
#include "libraries/temperature/TH02_dev.cpp"
#include "libraries/clock/RTClib.cpp"

#define SERVO_PIN_1 9
#define SERVO_PIN_2 8

// Servo servo;
int sPosition1 = 0;
int sPosition2 = 0;

Servo servo_1;
Servo servo_2;

RTC_DS1307 rtc;

void setup() {

  Serial.begin(57600);

  // Temperature sensor
  delay(150);
  TH02.begin();
  delay(100);

  // Clock
  while (!rtc.begin());
  Serial.println("RTC is NOT running!");
  rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));

  // Servo
  servo_1.attach(SERVO_PIN_1);
  servo_2.attach(SERVO_PIN_2);

  // Activate the built-in LED
  pinMode(LED_BUILTIN, OUTPUT);
}

bool systemStatus(DateTime now) {
  bool timeCheck = now.minute() != 165;   // 165 is a time error
  bool tempCheck = TH02.ReadTemperature() > 0 && TH02.ReadTemperature() < 80;
  return timeCheck && tempCheck;
}

void moveServo(int position) {
  servo_1.write(position);
  servo_2.write(position);
  delay(15);
}

void loop() {
  DateTime now = rtc.now();

  if (systemStatus(now)) {
    digitalWrite(LED_BUILTIN, HIGH);
  } else {
    digitalWrite(LED_BUILTIN, LOW);
  }

  Serial.println("-------------------------");
  Serial.print("Time ");
  Serial.print(now.hour(), DEC);
  Serial.print(":");
  Serial.println(now.minute(), DEC);

  Serial.print("Temperature: ");
  Serial.println(TH02.ReadTemperature());

  if (TH02.ReadTemperature() > 20) {
    for (int pos = 0; pos <= 360; pos += 1) {
      moveServo(pos);
    }
  }
}
