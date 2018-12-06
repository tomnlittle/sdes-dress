
#include "Arduino.h"
#include "Wire.h"

// #include "libraries/temperature/TH02_dev.cpp" // Temperature sensor library
// #include "libraries/light/light.cpp" // Light sensor library
// Clock sensor library
#include "libraries/servo/servo.cpp"

// LightSensor light(A10);

ServoActuator servo(10);


void setup() {
  Serial.begin(9600);

  // setupTemperature();
}


void loop() {

  servo.UpdateLocation(180);

  //  float value = light.ReadLight();

  //  Serial.println(value);

  //  float temper = readTemperature();
  //  Serial.println("Temperature: ");
  //  Serial.print(temper);
  //  Serial.println("C\r\n");

  //  float humidity = readHumidity();
  //  Serial.println("Humidity: ");
  //  Serial.print(humidity);
  //  Serial.println("%\r\n");


   delay(1000);
}

// float readTemperature() {
//   return TH02.ReadTemperature();
// }

// float readHumidity() {
//   return TH02.ReadHumidity();
// }

// void setupTemperature() {
//   /* Power up,delay 150ms,until voltage is stable */
//   delay(150);

//   /* Reset HP20x_dev */
//   TH02.begin();
//   delay(100);
// }
