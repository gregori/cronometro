#include <Arduino.h>
#include <Wire.h>
#include <Chronometer.h>
#include <TimerOne.h>
#include "constants.h"
#include <LiquidCrystal_I2C.h>
#include <ChronometerPrinter.h>
#include <SerialChronometerPrinter.h>

Chronometer *chronometer;
ChronometerPrinter *printer;
LiquidCrystal_I2C *lcd;


void setup() {
  chronometer = new Chronometer(PIN_INI, PIN_FIN);
  printer = new SerialChronometerPrinter(9600);
}

void loop() {
  chronometer->run();
  ChronometerTime time = chronometer->getTime();
  printer->printTime(time.minutes, time.seconds, time.centiseconds);
}
