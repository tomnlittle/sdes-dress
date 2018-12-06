
#include <Servo.h>
#include <Wire.h>
#include <Arduino.h>

#define SERVO_DELAY      100

class ServoActuator {
  public:
    ServoActuator(int pin = 10);
    void UpdateLocation(int);

  private:
    Servo servo;
    int currentDegree;
};
