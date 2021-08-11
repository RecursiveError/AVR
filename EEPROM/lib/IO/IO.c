/*  Autor:RecursiveError
biblioteca com as funções basicas de perifericos E operações para manipulação de bits
*/

#include "IO.h"
#include "Register/Register.h"

//define a função do pino
void pinMode(uint8_t pin, uint8_t std){
    if(pin < 8){
        if(std){
            Setbit(DDRD, pin);
        }else{
            Clrbit(DDRD, pin);
        }
    }

    if(pin > 7){
        if(std){
            Setbit(DDRB, (pin-8));
        }else{
            Clrbit(DDRB, (pin-8));
        }
    }
}

//define o estado do pino 
void digitalWrite(uint8_t pin, uint8_t std){
    if(pin < 8){
        if(std){
            Setbit(PORTD, pin);
        }else{
            Clrbit(PORTD, pin);
        }
    }
    
    if(pin > 7){
        if(std){
            Setbit(PORTB, (pin-8));
        }else{
            Clrbit(PORTB, (pin-8));
        }
    }
}

//le o valor do pino (apenas para INPUT)
int digitalRead(uint8_t pin){
    if(pin < 8){
            return Tstbit(PIND, pin);
    }
    if(pin > 7){
            return Tstbit(PINB, (pin-8));
    }
}