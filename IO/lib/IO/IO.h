#ifndef _IO_H
#define _IO_H

/*  Autor:RecursiveError
biblioteca com as funções basicas de perifericos E operações para manipulação de bits
*/

//Liga o bit indicado no ponteiro arg 
#define bitSet(arg, bit) (arg |= (1<<bit))

//Desliga o bit indicado no ponteiro arg
#define bitClr(arg, bit) (arg &= ~(1<<bit))

//Inverte o estado do bit indicado no ponteiro arg
#define bitFlp(arg, bit) (arg ^= (1<<bit))

//Testa o estado do bit indicado no ponteiro arg
#define bitTst(arg, bit) (arg &  (1<<bit))

#define OUTPUT 1
#define INPUT  0
#define HIGH   1
#define LOW    0

//Define o estado do registrador de direçao OUTPUT(1) INPUT(0)
void pinMode(int pin, int std);

//Define o estado do registrador de OUTPUT HIGH(1) liga a porta LOW(0) desliga
void digitalWrite(int pin, int std);

//Retorna o estado do bit (Apenas para INPUT)
int digitalRead(int pin);


#endif