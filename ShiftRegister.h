#include <Arduino.h>

class ShiftRegister {
 private:
	int dataPin;
	int shiftPin;
	int storePin;
	int size;
	int *states;
	bool changed;
 public:
	 ShiftRegister(int shiftPin, int storePin, int dataPin, int size);
	void flush();
	void setState(int index, int value);
	void on(int index);
	void off(int index);
};
