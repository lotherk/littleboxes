#include "ShiftRegister.h"

ShiftRegister::ShiftRegister(int shiftPin, int storePin, int dataPin, int size)
{
	this->shiftPin = shiftPin;
	this->storePin = storePin;
	this->dataPin = dataPin;
	this->size = size;
	this->states = (int *)malloc(size * sizeof(int));
	this->changed = false;
	for(int i = 0; i < size; i++) {
		this->states[i] = 0;
	}
}

void ShiftRegister::setState(int index, int state)
{
	if (index < this->size) {
		this->states[index] = state;
		this->changed = true;
	}
}

void ShiftRegister::on(int index)
{
	this->setState(index, 1);
}

void ShiftRegister::off(int index)
{
	this->setState(index, 0);
}

void ShiftRegister::flush()
{
	if (!this->changed)
		return;

	digitalWrite(this->storePin, LOW);

	for (int i = this->size; i >= 0; i--) {
		digitalWrite(this->shiftPin, LOW);
		digitalWrite(this->dataPin, this->states[i]);
		digitalWrite(this->shiftPin, HIGH);
	}

	digitalWrite(this->storePin, HIGH);
}
