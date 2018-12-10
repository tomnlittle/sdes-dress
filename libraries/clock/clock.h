#include "Arduino.h"
#include <Wire.h>

// look into this bullshit
#include "lib/DS1307.h"
#include "lib/DS1307.cpp"

class Clock {
  public:
    Clock(void);
    float readClock(void);
    void setClock(float);
    void printTime(void);

  private:
    DS1307 clock;
};
