/*  Autor:RecursiveError
biblioteca com as funções basicas de perifericos E operações para manipulação de bits
*/

#ifndef _IO_H
#define _IO_H

#include <stdint.h>


#define HIGH   1
#define LOW    0
#define OUTPUT 1
#define INPUT  0

//liga o bit no ponteiro
#define Setbit(ptr, bit) (ptr |= (1<<bit))

//limpa o bit no ponteiro
#define Clrbit(ptr, bit) (ptr &= ~(1<<bit))

//inverte o estado do bit no ponteiro
#define Flpbit(ptr, bit) (ptr ^= (1<<bit))

//le o estado do ponteiro
#define Tstbit(ptr, bit) (ptr & (1<<bit))

//deine a função do pino
void pinMode(uint8_t pin, uint8_t std);

//define o estado do pino
void digitalWrite(uint8_t pin, uint8_t std);

//le o estado do pino(apenas para INPUT)
int digitalRead(uint8_t pin);

#endif