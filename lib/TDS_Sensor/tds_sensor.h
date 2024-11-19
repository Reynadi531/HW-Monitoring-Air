#include <Arduino.h>

class TDSSensor {
  public:
    TDSSensor();
    void setAref(float aref);
    void setPin(int pin);
    void begin();
    float getTDSValue();
    void setConstantaCalibration(float constanta);
    void update();
  private:
    int _pin;
    float _aref;
    float _constanta;
    float temperature;
    float tdsValue;
    float analogValue;
    float adcRange;
    float voltage;
    float ecValue;
    float ecValue25;
    float tdsFactor;
};