#include <Arduino.h>
#include <ChronometerLcd.h>
#include <TimerOne.h>
#include "constants.h"


ChronometerLcd *lcd;
unsigned long centiseconds = 0;
unsigned int seconds = 0;
unsigned int minutes = 0;

enum Mode {
  RUN,
  RESET,
  PAUSE
};

Mode mode = RESET;

void setup() {
  Serial.begin(9600);
  lcd = new ChronometerLcd();
  lcd->printHeader();
  lcd->printHello();
  Timer1.initialize(10000);
  Serial.println("Cronômetro");
}

void timerIsr() {
  centiseconds++;
  seconds = centiseconds / 100;
  minutes = seconds / 60;
}

void resetMode() {
  Timer1.detachInterrupt();
  centiseconds = 0;
  seconds = 0;
  minutes = 0;
  lcd->printTime(minutes, seconds, centiseconds);
  Serial.println((String) minutes + ":" + (String) seconds + "." + (String) centiseconds);
}

void pauseMode() {
  Timer1.detachInterrupt();
}

bool isStartReceiver() {
  return digitalRead(PIN_INI) == HIGH;
}

bool isStopReceiver() {
  return digitalRead(PIN_FIN) == HIGH;
}

void runMode() {
  Timer1.attachInterrupt(timerIsr);
  lcd->printTime(minutes, seconds, centiseconds);
  Serial.println((String) minutes + ":" + (String) seconds + "." + (String) centiseconds);
}

void checkReceiver() {
  if (isStartReceiver()) {
    mode = RUN;
    Serial.println("Mode Run");
  } else if (isStopReceiver()) {
    mode = PAUSE;
    Serial.println("Mode Pause");
  }
}

void modeAction() {
  switch (mode) {
    case RUN:
      runMode();
      break;
    case RESET:
      resetMode();
      break;
    case PAUSE:
      pauseMode();
      break;
    default:
      resetMode();
      break;
  }
}

void loop() {
  checkReceiver();

  modeAction();
}
