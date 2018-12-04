
#include "Arduino.h"
#include "Wire.h"

// Temperature sensor library
#include "libraries/temperature/TH02_dev.cpp"

// Light sensor library

// Clock sensor library

void setupTemperature() {
  /* Power up,delay 150ms,until voltage is stable */
  delay(150);

  /* Reset HP20x_dev */
  TH02.begin();
  delay(100);
}

void setup() {
  Serial.begin(9600);

  setupTemperature();
}

float readTemperature() {
  return TH02.ReadTemperature();
}

float readHumidity() {
  return TH02.ReadHumidity();
}

void loop() {
   float temper = readTemperature()
   Serial.println("Temperature: ");
   Serial.print(temper);
   Serial.println("C\r\n");

   float humidity = readHumidity();
   Serial.println("Humidity: ");
   Serial.print(humidity);
   Serial.println("%\r\n");
   delay(1000);
}
