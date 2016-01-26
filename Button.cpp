#include "Button.h"

bool SUCCESS;
bool FAIL;
Button::Button() {}

Button::Button(int pin) {
  this->pin = pin;
  SUCCESS = true;
  FAIL = false;
}

Button::Button(int pin, int mode) {
  this->pin = pin;
  this->mode = mode;
  if(mode == INPUT) {
    SUCCESS = true;
    FAIL = false;
  } else {
    SUCCESS = false;
    FAIL = true;
  }
  pinMode(this->pin, this->mode);

}

bool Button::isPressed() {
  
  if(digitalRead(this->pin)) return SUCCESS;
  return FAIL;
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
    return SUCCESS;
    state = true;
  }
  if(this->isReleased()) {
    state = false;
  }
  return FAIL;
}
