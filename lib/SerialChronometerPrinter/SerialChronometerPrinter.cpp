#include "SerialChronometerPrinter.h"
#include <Arduino.h>

SerialChronometerPrinter::SerialChronometerPrinter(int baudRate)
{
    Serial.begin(baudRate);
}

void SerialChronometerPrinter::printTitle()
{
    Serial.println("Cronômetro");
}

void SerialChronometerPrinter::printTime(int minutes, int seconds, int centiseconds)
{
    Serial.println((String) minutes + ":" + (String) seconds + "." + (String) centiseconds);
}
