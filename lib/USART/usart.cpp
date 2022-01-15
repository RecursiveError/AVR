/*
Programa: USART
Autor: RecursiveError

lib para comunicação sarial baseada no manual do fabricante
*/

#include "usart.hpp"
#include "avr/io.h"
#include "stdint.h"


namespace usart {
    Usart& Usart::enable(unsigned int ubrr){
        uint8_t rate = F_CPU/16/ubrr-1;
        //ajusta a transmissão
        UBRR0H = (uint8_t) (rate >> 8);
        UBRR0L = (uint8_t) rate;

        //habilita os pinos de RX/TX
        UCSR0B = (1<<RXEN0)|(1<<TXEN0);

        //modo de 8 bits com 2 bits de parada
        UCSR0C = (1<<USBS0) | (3<<UCSZ00);
        return *this;
    }

    Usart& Usart::disable(){
        UBRR0H = 0;
        UBRR0L = 0;
        UCSR0B = 0;
        return *this;
    }

    Usart& Usart::transmit(unsigned char data){
        while(!(UCSR0A & (1<<UDRE0)));
        UDR0 = data;
        return *this;
    }

    unsigned char Usart::recive(){
        while(!(UCSR0A & (1<<RXC0)));
        return UDR0;
    }

    Usart& Usart::flush(){
        char dummy;
        while(UCSR0A & (1<<RXC0)) dummy = UDR0;
        return *this;
    }

    bool Usart::available(){
        return UCSR0A & (1<<RXC0);
    }

}
