#include "RGB.h"
#include "IO.h"


void rgbInit(int pinR, int pinB, int pinG){
    led.REDP = pinR;
    led.BLUEP = pinB;
    led.GREENP = pinG;
    pinMode(pinR, OUTPUT);
    pinMode(pinB, OUTPUT);
    pinMode(pinG, OUTPUT);
}


void rgbColor(int color){

    if(color & RED){
        digitalWrite(led.REDP, HIGH);
    }else{
        digitalWrite(led.REDP, LOW);
    }

    if(color & GREEN){
        digitalWrite(led.GREENP, HIGH);
    }else{
        digitalWrite(led.GREENP, LOW);
    }

    if(color & BLUE){
        digitalWrite(led.BLUEP, HIGH);
    }else{
        digitalWrite(led.BLUEP, LOW);
    }
} 


void turnOn(int color){
    if(color & RED){
        digitalWrite(led.REDP, HIGH);
    }
    if(color & GREEN){
        digitalWrite(led.GREENP, HIGH);
    }
    if(color & BLUE){
        digitalWrite(led.BLUEP, HIGH);
    }
}

void turnOff(int color){
    if(color & RED){
        digitalWrite(led.REDP, LOW);
    }
    if(color & GREEN){
        digitalWrite(led.GREENP, LOW);
    }
    if(color & BLUE){
        digitalWrite(led.BLUEP, LOW);
    }
}

