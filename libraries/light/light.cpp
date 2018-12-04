
/****************************************************************************/
/***        Include files                                                 ***/
/****************************************************************************/
#include "light.h"
#include <Wire.h>
#include <Arduino.h>

LightSensor::LightSensor(int pin) {
  pinNumber = pin;
}

float LightSensor::ReadLight(void) {
  return analogRead(pinNumber);
}
