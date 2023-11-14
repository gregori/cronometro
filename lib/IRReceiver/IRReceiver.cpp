
#include "IRReceiver.h"

IRReceiver::IRReceiver(int pin) {
  this->pin = pin;
  pinMode(pin, INPUT);
}

bool IRReceiver::isReceiving() {
  return getAnalogValue() > threshold;
}

int IRReceiver::getAnalogValue()
{
  return analogRead(pin);
}
