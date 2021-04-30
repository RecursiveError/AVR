/*
Autor: RecursiveError

Header para o mapeamento dos perifericos do Atmel328p no Arduino uno.
*Apenas para estudo de sistemas embarcados
**são mapeados apenas os pinos digitais (1 a 13)

*/
#ifndef _REGISTER_H
#define _REGISTER_H

//Criar ponteiros para os perifericos 
#define makeRegister(mem) (*(volatile unsigned char*)(mem + 0x20))

#define PINB  makeRegister(0x03)
#define DDRB  makeRegister(0x04)
#define PORTB makeRegister(0x05)

#define PIND  makeRegister(0x09)
#define DDRD  makeRegister(0x0A)
#define PORTD makeRegister(0x0B)



#endif