#include <Arduino.h>

class AnalogButton {
private:
  int *resistorValues;
  int pin;
  int rvSize;
  int diff;
  bool inRange(int val, int res);
public:
  AnalogButton();
  void setPin(int pin);
  int getPin();
  void setResistorValues(int *resistorValues, int rvSize);
  void setDiff(int diff);
  int read();
};
