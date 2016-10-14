#include <Arduino.h>

class Multiplex {
 private:
	int *controlPins;
	byte *muxChannel;
	uint8_t common;
	byte sizePins;
	void setup();
 public:
	 Multiplex();
	 Multiplex(uint8_t common, int *controlPins, int sizePins,
		   byte * muxChannel);
	void setCommon(uint8_t common);
	void setControlPins(int *controlPins, int size);
	void setMuxChannel(byte * muxChannel);
	void selectChannel(uint8_t channel);
	int digitalRead();
	int analogRead();
	uint8_t getCommon();
	void digitalWrite(int value);
	void analogWrite(int value);
};
