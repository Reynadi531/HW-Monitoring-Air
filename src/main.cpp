#include <Arduino.h>
#include <tds_sensor.h>

#define AREF_V 3.3
#define TDS_PIN 15

TDSSensor tdsSensor;

void setup()
{
  Serial.begin(115200);
  tdsSensor.begin();
  tdsSensor.setPin(TDS_PIN);
  tdsSensor.setAref(AREF_V);
}

void loop()
{
  tdsSensor.update();
  Serial.print("TDS Value: ");
  Serial.println(tdsSensor.getTDSValue());
  delay(100);
}