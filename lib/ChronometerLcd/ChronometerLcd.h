#ifndef CHRONOMETER_LCD_H
#define CHRONOMETER_LCD_H

#include <LiquidCrystal_I2C.h>

class ChronometerLcd
{
private:
    LiquidCrystal_I2C *lcd;

public:
    ChronometerLcd();
    ~ChronometerLcd();
    void printHeader();
    void printTime(int minutes, int seconds, int centiseconds);
    void printHello();
};

#endif // CHRONOMETER_LCD_H
