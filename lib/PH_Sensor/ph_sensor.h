#include <Arduino.h>

class PHSensor
{
    private:
        int pin;
        float aref;
        float voltage;
        float adcRange;
        float phValue;
        float analogValue;
    public:
        PHSensor();
        void setupPin(int pin);
        void setAref(float aref);
        void setAdcRange(float adcRange);
        void begin();
        float getPHValue();
        float getVoltage();
        float getAnalogValue();
        void update();
};