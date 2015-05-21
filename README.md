# littleboxes

This is a small library I use in my arduino projects. It is a set of classes you can use for [Button](src/Button.h)s, [Encoder](src/Encoder.h)s and, what I call, an [AnalogButton](src/AnalogButton.h).

I use these for my *little boxes*, like [boxwax](https://github.com/lotherk/boxwax) or [joynardo](https://github.com/lotherk/joynardo).

### Button

A [Button](src/Button.cpp) has a digital input and is either pressed or released.

```cpp
Button b;

void setup() {
  // ...
  pinMode(4, INPUT);
  b.setPin(4);
  // ...
}

void loop() {
  // ...
  if(b.isPressed()) {
    // Button is pressed
  } else {
    // Button is released
  }
  // ...
}
```

### AnalogButton

An [AnalogButton](src/AnalogButton.cpp) has multiple states and is connected to an analog pin. States are defined by resistor values.

```cpp
int aResistorValues[2] = { 1023, 575 };
Button aButton;

void setup() {
  // ...
  aButton.setPin(A0);
  aButton.setResistorValues(aResistorValues, 2); // pass the size of aResistorValues
  // ...
}

void loop() {
  switch(aButton.read()) {
    case 0:
      // first state, value is 1023
      break;
    case 1:
      // second state, value is 575
      break;
    case -1:
      // faulty state, value on A0 is not defined in resistorValues
      break;
  }
}
```

### Encoder

An [Encoder](src/Encoder.cpp) can be turned left, turned right and increases or decreases a value. If you're using a clickable encoder, use [Button](src/Button.cpp) for the click. An encoder uses 2 digital pins. It uses NO interrupt so values might not be 100% accurate.

```cpp
Encoder encoder;

void setup() {
  // ...
  encoder.setPins(3, 4);
  // ...
}

void loop() {
  // ...
  if(encoder.isClickedLeft()) {
    // encoder is turned left by 1 click
  }
  if(encoder.isClickedRight()) {
    // encoder is turned right by 1 click
  }
  Serial.println(encoder.getValue());
  // ...
}
```

### Multiplex

[Multiplex](src/Multiplex.cpp) example for a 16ch analog multiplexer (4067).

```cpp
// define control channels
byte muxChannel[] = {
  0b0000, // ch 0
  0b1000, // ch 1
  0b0100, // ch 2
  0b1100, // ch 3
  0b0010, // ch 4
  0b1010, // ch 5
  0b0110, // ch 6
  0b1110, // ch 7
  0b0001, // ch 8
  0b1001, // ch 9
  0b0101, // ch 10
  0b1101, // ch 11
  0b0011, // ch 12
  0b1011, // ch 13
  0b0111, // ch 14
  0b1111  // ch 15
};

// define control pins s0 - s3
int ctrlPins[] = { 2, 3, 4, 5 };

Multiplex mplex;

void setup() {
  // ...
  mplex.setCommon(A0);
  mplex.setControlPins(ctrlPins, 4); // pass size of ctrlPins
  mplex.setMuxChannel(muxChannel);
  // ...
}

void loop() {
  // read channel 5
  mplex.selectChannel(5);
  if(mplex.digitalRead() == HIGH) {
    // channel 5 is HIGH
  }
}
```

#### With a button

A [Button](src/Button.cpp) example. Button is connected to channel 4:

```cpp
// define control channels
byte muxChannel[] = {
  0b0000, // ch 0
  0b1000, // ch 1
  0b0100, // ch 2
  0b1100, // ch 3
  0b0010, // ch 4
  0b1010, // ch 5
  0b0110, // ch 6
  0b1110, // ch 7
  0b0001, // ch 8
  0b1001, // ch 9
  0b0101, // ch 10
  0b1101, // ch 11
  0b0011, // ch 12
  0b1011, // ch 13
  0b0111, // ch 14
  0b1111  // ch 15
};

// define control pins s0 - s3
int ctrlPins[] = { 2, 3, 4, 5 };

Multiplex mplex;

Button mButton;

void setup() {
  // ...
  mplex.setCommon(A0);
  mplex.setControlPins(ctrlPins, 4); // pass size of ctrlPins
  mplex.setMuxChannel(muxChannel);

  mButton.setPin(mplex.getCommon());
  // ...
}

void loop() {
  // read channel 4
  mplex.selectChannel(4);
  if(mButton.isPressed()) {
    // Button is pressed.
  }
}
```
