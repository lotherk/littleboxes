#include <Arduino.h>
#define LEFT -1
#define RIGHT 1
class Encoder {
private:
  int pinMSB;
  int pinLSB;
  uint32_t timer;
  uint32_t last_encoded;
  uint32_t value;
  int timeout_ms;
  int prev;
  int update();
public:
  Encoder();
  void setPins(int MSB, int LSB);
  void setTimeout(int timeout);
  uint32_t getValue();
  bool isClickedLeft();
  bool isClickedRight();
};
