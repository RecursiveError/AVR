/*
Programa: USART
Autor: RecursiveError

lib para comunicação sarial baseada no manual do fabricante
*/

#ifndef USART_HPP
#define USART_HPP

#define DEFULT_UBRR 9600u
namespace usart{
    class Usart{
        public:
            Usart& enable(unsigned int ubrr = DEFULT_UBRR);
            Usart& disable();
            Usart& transmit(unsigned char data);
            unsigned char recive();
            Usart& flush();
            bool available();
    };
}


#endif