#ifndef CHRONOMETER_H
#define CHRONOMETER_H

#include <IRReceiver.h>
#include <Arduino.h>

enum Mode {
        RUN,
        RESET,
        PAUSE
};

typedef struct ChronometerTime
{
        int minutes;
        int seconds;
        int centiseconds;
} ChronometerTime;


class Chronometer {
    private:
        static unsigned long centiseconds;
        static unsigned int seconds;
        static unsigned int minutes;

        unsigned long startTime;
        unsigned long stopTime;
        bool isRunning;
        Mode mode;
        IRReceiver *startReceiver;
        IRReceiver *stopReceiver;

        void start();
        void stop();
        void strategy();
        void updateMode();
        static void timeIsr();

    public:
        Chronometer(byte pinIni, byte pinFin);
        void run();
        static ChronometerTime getTime();
        void reset();
        int getMode();
};

#endif // CHRONOMETER_H
