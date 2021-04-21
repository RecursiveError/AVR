/*
Programa: Serial
Autor: RecursiveError

Esse programa é baseado no datasheet do atmel328p

Não é um softserial, pois esse topico envolve interrupções e timers q não são temas
do topico de comunicação
*/


#include <Arduino.h>

void serial_init(unsigned int BAUD){
    unsigned int rate = F_CPU/16/BAUD-1;
    UBRR0H = (unsigned char) (rate>>8);
    UBRR0L = (unsigned char) rate;

    UCSR0B = (1<<RXEN0) | (1<<TXEN0);
    UCSR0C = (1<<USBS0) | (3<<UCSZ00);
}

void serial_send(unsigned int data){
    while(!(UCSR0A & (1<<UDRE0)));
    UDR0 = data;
}

unsigned char serial_recive(){
    while(!(UCSR0A & (1<<RXC0)));
    return UDR0;
}

void serial_flush(){
    unsigned char dummy;
    while(UCSR0A & (1<<RXC0)) dummy = UDR0;
}
