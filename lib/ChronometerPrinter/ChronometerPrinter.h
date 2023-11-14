
#ifndef CHRONOMETER_PRINTER_H
#define CHRONOMETER_PRINTER_H

class ChronometerPrinter {
public:
  virtual void printTitle() = 0;
  virtual void printTime(int minutes, int seconds, int centiseconds) = 0;

};

#endif