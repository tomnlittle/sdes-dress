
// BUILT-IN LIBRARIES
#include "Arduino.h"
#include "Wire.h"
#include "Servo.h"

// CUSTOM LIBRARIES
#include "libraries/clock/RTClib.cpp"

#define SERVO_PIN_1 9

// Servo servo;
int sPosition1 = 0;

Servo servo_1;

RTC_DS1307 rtc;

void setup() {

  Serial.begin(57600);

  // Clock
  while (!rtc.begin());
  Serial.println("RTC is NOT running!");
  rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));

  // Servo
  servo_1.attach(SERVO_PIN_1);

  // Activate the built-in LED
  pinMode(LED_BUILTIN, OUTPUT);
}

bool systemStatus(DateTime now) {
  bool timeCheck = now.minute() != 165;   // 165 is a time error
  return timeCheck;
}

void moveServo() {
  if (sPosition1 == 1) {
    for (int pos = 0; pos <= 180; pos += 1) {
      servo_1.write(pos);
      delay(15);
    }
    sPosition1 = 0;
  } else {
    for (int pos = 180; pos >= 0; pos -= 1) {
      servo_1.write(pos);
      delay(15);
    }
    sPosition1 = 1;
  }
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

  moveServo();

  delay(30 * 1000);
}
