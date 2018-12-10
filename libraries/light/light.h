#include <Arduino.h>
#include <Wire.h>

class LightSensor {
  public:
    LightSensor(int pin = 0);
    float ReadLight(void);

  private:
    int pinNumber;
};
