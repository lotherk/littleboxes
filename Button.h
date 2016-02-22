#include <Arduino.h>

class Button {
private:
  int pin;
  int mode;
  bool state;
  double timer;

public:
  Button();
  Button(int pin);
  Button(int pin, int mode);
  bool isPressed();
  bool isReleased();
  int getPin();
  void setPin(int pin);
  bool isPressedOnce();
};
