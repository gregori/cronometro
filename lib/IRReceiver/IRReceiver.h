
#ifndef IRRECEIVER_H
#define IRRECEIVER_H

#include <Arduino.h>

class IRReceiver {
  public:
    IRReceiver(int pin);
    bool isReceiving();
    int getAnalogValue();

  private:
    byte pin;
    int threshold = 600;
};

#endif
