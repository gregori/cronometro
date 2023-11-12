#include <LiquidCrystal_I2C.h>
#include "ChronometerLcd.h"

ChronometerLcd::ChronometerLcd()
{
    lcd = new LiquidCrystal_I2C(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

    lcd->begin(16, 2);
    lcd->backlight();
}

ChronometerLcd::~ChronometerLcd()
{
}

void ChronometerLcd::printHeader()
{
    lcd->setCursor(0, 0);
    lcd->print("Cronometro");
}

void ChronometerLcd::printTime(int minutes, int seconds, int centiseconds)
{
    lcd->setCursor(0, 1);
    lcd->print(minutes / 10);
    lcd->setCursor(1, 1);
    lcd->print(minutes % 10);
    lcd->setCursor(2, 1);
    lcd->print(":");
    lcd->setCursor(3, 1);
    lcd->print(seconds / 10);
    lcd->setCursor(4, 1);
    lcd->print(seconds % 10);
    lcd->setCursor(5, 1);
    lcd->print(".");
    lcd->setCursor(6, 1);
    lcd->print(centiseconds / 10);
    lcd->setCursor(7, 1);
    lcd->print(centiseconds % 10);
}

void ChronometerLcd::printHello()
{
    lcd->setCursor(0, 0);
    lcd->print("Hello");
}