#include "Button.h"

Button::Button() {}

Button::Button(int pin) {
  this->pin = pin;
}

Button::Button(int pin, int mode) {
  this->pin = pin;
  this->mode = mode;
  pinMode(this->pin, this->mode);

}

bool Button::isPressed() {
  if(digitalRead(this->pin)) return true;
  return false;
}

bool Button::isReleased() {
  return !this->isPressed();
}

void Button::setPin(int pin) {
  this->pin = pin;
}

int Button::getPin() {
  return this->pin;
}

bool Button::isPressedOnce() {
  if(! state && this->isPressed()) {
    return true;
    state = true;
  }
  if(this->isReleased()) {
    state = false;
  }
  return false;
}
