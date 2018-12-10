
#include "light.h"

LightSensor::LightSensor(int pin) {
  pinNumber = pin;
}

float LightSensor::ReadLight(void) {
  return analogRead(pinNumber);
}
