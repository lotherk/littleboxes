#include "Encoder.h"

Encoder::Encoder() {
  this->value = 0;
  this->prev =  0;
  this->timeout_ms = 40;
}
void Encoder::setPins(int MSB, int LSB) {
  this->pinMSB = MSB;
  this->pinLSB = LSB;
}
int Encoder::update() {
  int MSB = digitalRead(this->pinMSB);
  int LSB = digitalRead(this->pinLSB);
  int last_value = this->value;
  int encoded = (MSB << 1) | LSB;
  int sum = (this->last_encoded << 2) | encoded;

  if(sum == 0b1101 || sum == 0b0100 || sum == 0b0010 || sum == 0b1011) {
    this->value++;
  }
  if(sum == 0b1110 || sum == 0b0111 || sum == 0b0001 || sum == 0b1000) {
    this->value--;
  }

  this->last_encoded = encoded;

  if(this->prev > 5 || this->prev < -5) {
    this->prev = 0;
  }

  if(last_value < this->value) {
    if(this->prev < 4) this->prev++;
  } else if(last_value < this->value) {
    if(this->prev > -4) this->prev--;
  }

  if(this->timer > 0 && (millis() - this->timer) >= this->timeout_ms) {
    this->prev = 0;
    this->timer = 0;
  }

  if(this->prev == 4) {
    if(this->timer = 0) this->timer = millis();
    return RIGHT;
  } else if(this->prev == -4) {
    if(this->timer = 0) this->timer = millis();
    return LEFT;
  }

  return 0;
}

bool Encoder::isClickedLeft() {
  if(this->update() == LEFT) return true;
  return false;
}

bool Encoder::isClickedRight() {
  if(this->update() == RIGHT) return true;
  return false;
}

void Encoder::setTimeout(int timeout) {
  this->timeout_ms = timeout;
}

uint32_t Encoder::getValue() {
  this->update();
  return this->value;
}
