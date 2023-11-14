#include "Chronometer.h"
#include <Arduino.h>
#include <TimerOne.h>

unsigned long Chronometer::centiseconds = 0;
unsigned int Chronometer::seconds = 0;
unsigned int Chronometer::minutes = 0;

void Chronometer::start()
{
    Timer1.attachInterrupt(Chronometer::timeIsr);
}

void Chronometer::stop()
{
    Timer1.detachInterrupt();
}

void Chronometer::reset()
{
    Timer1.detachInterrupt();
    centiseconds = 0;
    seconds = 0;
    minutes = 0;
}

void Chronometer::strategy()
{
    switch (mode)
    {
    case RUN:
        start();
        break;
    case PAUSE:
        stop();
        break;
    case RESET:
        reset();
        break;
    default:
        reset();
        break;
    }
}

void Chronometer::updateMode()
{
    if (!startReceiver->isReceiving() && mode == RESET) 
    {
        mode = RUN;
    }
    else if (!stopReceiver->isReceiving())
    {
        mode = PAUSE;
    }
}

void Chronometer::timeIsr()
{
    centiseconds++;
    seconds = centiseconds / 100;
    minutes = seconds / 60;
}

Chronometer::Chronometer(byte pinIni, byte pinFin)
{
    startReceiver = new IRReceiver(pinIni);
    stopReceiver = new IRReceiver(pinFin);
    isRunning = false;
    mode = RESET;
    Timer1.initialize(10000);
}

void Chronometer::run()
{
    updateMode();
    strategy();
}

ChronometerTime Chronometer::getTime()
{
    ChronometerTime time;
    time.minutes = minutes;
    time.seconds = seconds;
    time.centiseconds = centiseconds;

    return time;
}

int Chronometer::getMode()
{
    return startReceiver->getAnalogValue();
}
