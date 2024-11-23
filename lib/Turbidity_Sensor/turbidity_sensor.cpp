#include <Arduino.h>
#include <turbidity_sensor.h>

TurbiditySensor::TurbiditySensor()
{
    this->pin = 15;
    this->voltage = 3.3;
    this->adcRange = 4095.0;
}

void TurbiditySensor::setupPin(int pin) {
    this->pin = pin;
}

void TurbiditySensor::setAref(float aref) {
    this->voltage = aref;
}

void TurbiditySensor::setAdcRagne(float adcRange) {
    this->adcRange = adcRange;
}

void TurbiditySensor::begin() {
    pinMode(this->pin, INPUT);
    analogReadResolution(12);
}

float TurbiditySensor::getTurbidityValue() {
    return this->turbidityValue;
}

float TurbiditySensor::getVoltage() {
    return this->voltage;
}

float TurbiditySensor::getAnalogValue() {
    return this->analogValue;
}

void TurbiditySensor::update() {
    this->analogValue = analogRead(this->pin);
    this->voltage = this->analogValue * (this->aref / this->adcRange);
    this->turbidityValue = map(voltage * 1000, 0.0 * 1000, this->aref * 1000, 0 * 1000, 1000 * 1000)/1000;
}