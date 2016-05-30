#include <wiringPi.h>
#include <iostream>
#include "IRSensor.h"

int IRTestMain(void)
{
    int SL; //der Zustand des linken Infrarotsensor
    int SR; //der Zustand des rechten Infrarotsensor
    wiringPiSetup();
    IRSensor_setup();//Initialisierung der PinMode 
    while(1)
    {
        SR = digitalRead(SensorRight);      // SR=1→der rechte Infrarotsensor befindet sich innerhalb schwarzer Linie;SR=0→ weisse Zone
        SL = digitalRead(SensorLeft);       // SL=1→der linke Infrarotsensor befindet sich innerhalb schwarzer Linie;SL=0→ weisse Zone
        if (SL == HIGH&&SR==HIGH)
            run();                          // die zwei Infrarotsensor befinden sich innerhalb der schwarzen Linie→das ist gut
        else if (SL == LOW & SR == HIGH)    // rechter IRSensor ist in weisse Zone, das Auto braucht links zu fahren
            left();
        else if (SR == LOW & SL == HIGH)    // linker IRSensor ist in weisse Zone, das Auto braucht rechts zu fahren
            right();
        else                                // zwei Sensoren sind in weisser Zone→stopp
            brake();
    }
    return 0;
}
