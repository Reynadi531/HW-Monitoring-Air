#include <Arduino.h>
#include <ph_sensor.h>

#define AREF_V 5.0
#define PH_PIN 13

PHSensor phSensor;

void setup()
{
  Serial.begin(115200);
  phSensor.setupPin(PH_PIN);
  phSensor.setAref(AREF_V);
  phSensor.setAdcRange(1023);
  phSensor.begin();
}

void loop()
{
  phSensor.update();
  Serial.printf("Voltage: %f\n", phSensor.getVoltage());
  delay(1000);
}