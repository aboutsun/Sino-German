#include <wiringPi.h>
#include <iostream>
#include "IRSensor.h"

int main(void)
{
    int SL; //der Zustand des linken Infrarotsensor
    int SR; //der Zustand des rechten Infrarotsensor
    wiringPiSetup();
    IRSensor_setup();//Initialisierung der PinMode 
    while(1)
    {
        SR = digitalRead(SensorRight);      // SR=1→der rechte Infrarotsensor befindet sich innerhalb weisser zone;SR=0→ schwarze Linie
        SL = digitalRead(SensorLeft);       // SL=1→der linke Infrarotsensor befindet sich innerhalb weisser zone;SL=0→ schwarze Linie
        if (SL == LOW&&SR==LOW)
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
