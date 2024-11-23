#include <Arduino.h>

class TurbiditySensor
{
    private:
        int pin;
        float voltage;
        float aref;
        float turbidityValue;
        float analogValue;
        float adcRange;
        float mapValue(float x, float in_min, float in_max, float out_min, float out_max);
    public:
        TurbiditySensor();
        void setupPin(int pin);
        void setAref(float aref);
        void setAdcRagne(float adcRange);
        void begin();
        float getTurbidityValue();
        float getVoltage();
        float getAnalogValue();
        void update();    
};