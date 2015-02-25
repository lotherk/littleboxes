#include "AnalogButton.h"

AnalogButton::AnalogButton() {
  this->diff = 1;
}

int AnalogButton::read() {
  int val = analogRead(this->pin);
  for(int i = 0; i < this->rvSize; i++) {
    if(this->inRange(val, this->resistorValues[i])) {
      return i;
    }
  }
  return -1;
}

bool AnalogButton::inRange(int val, int res) {
  if(val == res) return true;
  float diff = (float) res - val;
  if(diff < 0) diff *= -1;
  if(diff > this->diff) return false;
  return true;
}

void AnalogButton::setPin(int pin) {
  this->pin = pin;
}

int AnalogButton::getPin() {
  return this->pin;
}

void AnalogButton::setResistorValues(int *resistorValues, int size) {
  this->resistorValues = resistorValues;
  this->rvSize = size;
}
