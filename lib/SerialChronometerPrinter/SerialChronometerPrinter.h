
#ifndef SERIAL_CHRONOMETER_PRINTER_H
#define SERIAL_CHRONOMETER_PRINTER_H

#include "ChronometerPrinter.h"

class SerialChronometerPrinter : public ChronometerPrinter {
public:
    SerialChronometerPrinter(int baudRate);
    void printTitle() override;
    void printTime(int minutes, int seconds, int centiseconds) override;
};

#endif // SERIAL_CHRONOMETER_PRINTER_H
