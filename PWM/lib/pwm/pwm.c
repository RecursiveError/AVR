/*
Codigo: PWM
Autor: RecursiveError
Lib de exemplo para uso de 2 portas PWM
*/

#include <avr/io.h>
#include "IO.h"

void pwm_init(){
    pinMode(5, OUTPUT);
    pinMode(6, OUTPUT);
    TCCR0A = 0xF3; //Fast PWM (inverting mode)
    TCCR0B = 4; //prescaler 256
    //DESLIGA O PWM
    OCR0A = 0;
    OCR0B = 0;
}

void set_duty(char pin, char value){
   if(pin == 5) OCR0A = value;
   if(pin == 6) OCR0B = value;
}