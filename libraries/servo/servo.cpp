#include "servo.h"
#include <Wire.h>
#include <Arduino.h>

ServoActuator::ServoActuator(int pin) {
  servo.attach(pin);
}

void ServoActuator::UpdateLocation(int degree) {

  for (int pos = 0; pos <= 180; pos += 1) {
    servo.write(pos);
    delay(SERVO_DELAY);
  }
  for (int pos = 180; pos >= 0; pos -= 1) {
    servo.write(pos);
    delay(SERVO_DELAY);
  }

  Serial.println(".");
}
