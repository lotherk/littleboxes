#include "Multiplex.h"

Multiplex::Multiplex(uint8_t common, int *controlPins, int sizePins,
		     byte * muxChannel)
{
	this->controlPins = controlPins;
	this->muxChannel = muxChannel;
	this->sizePins = sizePins;
	this->common = common;
	this->setup();
}

void Multiplex::setup()
{
	for (int i = 0; i < this->sizePins; i++) {
		pinMode(this->controlPins[i], OUTPUT);
		::digitalWrite(this->controlPins[i], LOW);
	}
}

void Multiplex::selectChannel(uint8_t channel)
{
	byte muxch = this->muxChannel[channel];
	int i = this->sizePins - 1;
	for (byte mask = 0b0001; i >= 0; mask <<= 1) {
		if (muxch & mask) {
			::digitalWrite(this->controlPins[i], HIGH);
		} else {
			::digitalWrite(this->controlPins[i], LOW);
		}
		i--;
	}
}

int Multiplex::digitalRead()
{
	return::digitalRead(this->common);
}

void Multiplex::digitalWrite(int value)
{
	::digitalWrite(this->common, value);
}

int Multiplex::analogRead()
{
	return::analogRead(this->common);
}

void Multiplex::analogWrite(int value)
{
	::analogWrite(this->common, value);
}

void Multiplex::setCommon(uint8_t common)
{
	this->common = common;
}

void Multiplex::setControlPins(int *controlPins, int sizePins)
{
	this->controlPins = controlPins;
	this->sizePins = sizePins;
}

void Multiplex::setMuxChannel(byte * muxChannel)
{
	this->muxChannel = muxChannel;
}

uint8_t Multiplex::getCommon()
{
	return this->common;
}
