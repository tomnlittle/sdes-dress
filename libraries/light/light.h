
#include <Wire.h>
#include <Arduino.h>

class LightSensor {
  public:
    LightSensor(int pin = 0);
    float ReadLight(void);

  private:
    int pinNumber;
};
