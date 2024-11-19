#include <Arduino.h>
#include <tds_sensor.h>

#define AREF_V 3.3
TDSSensor tdsSensor;

void setup()
{
  Serial.begin(115200);
  tdsSensor.begin();
  tdsSensor.setPin(15);
  tdsSensor.setAref(AREF_V);
}

void loop()
{
  tdsSensor.update();
  Serial.print("TDS Value: ");
  Serial.println(tdsSensor.getTDSValue());
  delay(10000);
}