#include <Arduino.h>
#include <tds_sensor.h>
#include <EEPROM.h>

TDSSensor::TDSSensor() {
    this->_aref = 3.3;
    this->_constanta = 1.0;
    this->temperature = 25;
    this->tdsValue = 0;
    this->analogValue = 0;
    this->adcRange = 1024.0;
    this->voltage = 0;
    this->tdsFactor = 0.5;
}

void TDSSensor::setAref(float aref) {
    this->_aref = aref;
}

void TDSSensor::setPin(int pin) {
    this->_pin = pin;
}

float TDSSensor::getTDSValue() {
  return this->tdsValue;
}

void TDSSensor::begin() {
  pinMode(_pin, INPUT);
}

void TDSSensor::setConstantaCalibration(float constanta) {
  this->_constanta = constanta;
}

void TDSSensor::update() {
    this->analogValue = analogRead(this->_pin);
    this->voltage = this->analogValue / this->adcRange * this->_aref;
    this->ecValue = 133.42 * this->voltage * this->voltage * this->voltage - 255.86 * this->voltage * this->voltage + 857.39 * this->voltage;
    this->ecValue25  =  this->ecValue / (1.0+0.02*(this->temperature-25.0));
    this->tdsValue = this->ecValue25 * this->tdsFactor;
}
