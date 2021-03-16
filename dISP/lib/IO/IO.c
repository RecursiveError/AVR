#include "IO.h"
#include "Register/Register.h"
/*  Autor:RecursiveError
    biblioteca com as 3 funções basicas de perifericos
*/

//Define o estado do registrador de direçao OUTPUT(1) INPUT(0)
void pinMode(int pin, int std){
    if(std == OUTPUT){
        switch (pin)
        {
        case 0:  bitSet(DDRD, 0); break;
        case 1:  bitSet(DDRD, 1); break;
        case 2:  bitSet(DDRD, 2); break;
        case 3:  bitSet(DDRD, 3); break;
        case 4:  bitSet(DDRD, 4); break;
        case 5:  bitSet(DDRD, 5); break;
        case 6:  bitSet(DDRD, 6); break;
        case 7:  bitSet(DDRD, 7); break;
        case 8:  bitSet(DDRB, 0); break;
        case 9:  bitSet(DDRB, 1); break;
        case 10: bitSet(DDRB, 2); break;
        case 11: bitSet(DDRB, 3); break;
        case 12: bitSet(DDRB, 4); break;
        case 13: bitSet(DDRB, 5); break;
        default:
            break;
        }
    }
    if(std == INPUT){
        switch (pin)
        {
        case 0:  bitClr(DDRD, 0); break;
        case 1:  bitClr(DDRD, 1); break;
        case 2:  bitClr(DDRD, 2); break;
        case 3:  bitClr(DDRD, 3); break;
        case 4:  bitClr(DDRD, 4); break;
        case 5:  bitClr(DDRD, 5); break;
        case 6:  bitClr(DDRD, 6); break;
        case 7:  bitClr(DDRD, 7); break;
        case 8:  bitClr(DDRB, 0); break;
        case 9:  bitClr(DDRB, 1); break;
        case 10: bitClr(DDRB, 2); break;
        case 11: bitClr(DDRB, 3); break;
        case 12: bitClr(DDRB, 4); break;
        case 13: bitClr(DDRB, 5); break;
        default:
            break;
        }
    }
}

//Define o estado do registrador de OUTPUT HIGH(1) liga a porta LOW(0) desliga
void digitalWrite(int pin, int std){
    if(std == HIGH){
         switch (pin)
        {
        case 0:  bitSet(PORTD, 0); break;
        case 1:  bitSet(PORTD, 1); break;
        case 2:  bitSet(PORTD, 2); break;
        case 3:  bitSet(PORTD, 3); break;
        case 4:  bitSet(PORTD, 4); break;
        case 5:  bitSet(PORTD, 5); break;
        case 6:  bitSet(PORTD, 6); break;
        case 7:  bitSet(PORTD, 7); break;
        case 8:  bitSet(PORTB, 0); break;
        case 9:  bitSet(PORTB, 1); break;
        case 10: bitSet(PORTB, 2); break;
        case 11: bitSet(PORTB, 3); break;
        case 12: bitSet(PORTB, 4); break;
        case 13: bitSet(PORTB, 5); break;
        default:
            break;
        }
    }
    if(std == LOW){
        switch (pin)
        {
        case 0:  bitClr(PORTD, 0); break;
        case 1:  bitClr(PORTD, 1); break;
        case 2:  bitClr(PORTD, 2); break;
        case 3:  bitClr(PORTD, 3); break;
        case 4:  bitClr(PORTD, 4); break;
        case 5:  bitClr(PORTD, 5); break;
        case 6:  bitClr(PORTD, 6); break;
        case 7:  bitClr(PORTD, 7); break;
        case 8:  bitClr(PORTB, 0); break;
        case 9:  bitClr(PORTB, 1); break;
        case 10: bitClr(PORTB, 2); break;
        case 11: bitClr(PORTB, 3); break;
        case 12: bitClr(PORTB, 4); break;
        case 13: bitClr(PORTB, 5); break;
        default:
            break;
        }
    }
}

//Retorna o estado do bit (Apenas para INPUT)
int digitalRead(int pin){
    switch (pin){
    case 0:  return bitTst(PIND, 0);
    case 1:  return bitTst(PIND, 1);
    case 2:  return bitTst(PIND, 2);
    case 3:  return bitTst(PIND, 3);
    case 4:  return bitTst(PIND, 4);
    case 5:  return bitTst(PIND, 5);
    case 6:  return bitTst(PIND, 6);
    case 7:  return bitTst(PIND, 7);
    case 8:  return bitTst(PINB, 0);
    case 9:  return bitTst(PINB, 1);
    case 10: return bitTst(PINB, 2);
    case 11: return bitTst(PINB, 3);
    case 12: return bitTst(PINB, 4);
    case 13: return bitTst(PINB, 5);
    default: break;
    }
    return -1;
}

/*
A escolha do switch apenas por convenção 
no caso do Arduino uno as portas digitais ficam em sequencia
*/