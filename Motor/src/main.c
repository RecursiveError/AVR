#include "motor.h"

void _delay();

unsigned long int millis;

int main(void){
    initMotor();
    for(;;){
        turnR();
        _delay();

        off();
        _delay();

        turnL();
        _delay();

        off();
        _delay();

        millis++;
    }
}


void _delay(){
    for(volatile long int i = 0;i<100000;i++);
}