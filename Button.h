#include <Arduino.h>

class Button {
private:
  int pin;
  int mode;
  double timer;

public:
  Button();
  Button(int pin);
  Button(int pin, int mode=INPUT);
  bool isPressed();
  bool isReleased();
  int getPin();
  void setPin(int pin);
};
