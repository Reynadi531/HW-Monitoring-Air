#include <Arduino.h>
#include <ph_sensor.h>

PHSensor::PHSensor()
{
    this->pin = 15;
    this->voltage = 5.0;
    this->adcRange = 4095.0;
}

void PHSensor::setupPin(int pin) {
    this->pin = pin;
}

void PHSensor::setAref(float aref) {
    this->aref = aref;
}

void PHSensor::setAdcRange(float adcRange) {
    this->adcRange = adcRange;
}

void PHSensor::begin() {
    pinMode(this->pin, INPUT);
    analogReadResolution(10);
}

float PHSensor::getPHValue() {
    return this->phValue;
}

float PHSensor::getVoltage() {
    return this->voltage;
}

float PHSensor::getAnalogValue() {
    return this->analogValue;
}

void PHSensor::update() {
    this->analogValue = analogRead(this->pin);
    this->voltage = this->analogValue * (this->aref / this->adcRange);
}