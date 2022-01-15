/*  Autor:RecursiveError
biblioteca com as funções basicas de perifericos E operações para manipulação de bits
*/

#include "IO.hpp"
#include <avr/io.h>

namespace digitalIO{
    DigitalIO& DigitalIO::output(void){
        if(this->_pin < 8u){
            DDRD |= (1<<this->_pin);
        }else if(this->_pin < 14u){
            DDRB |= (1<<(this->_pin - 8u));
        }else if(this->_pin < 20u){
            DDRC |= (1<<(this->_pin - 14u));
        }
        return *this;
    }

    DigitalIO& DigitalIO::input(void){
        if(this->_pin < 8u){
            DDRD &= ~(1<<this->_pin);
        }
        if(this->_pin < 14u){
            DDRB &= ~(1<<(this->_pin - 8u));
        }else if(this->_pin < 20u){
            DDRC &= ~(1<<(this->_pin - 14u));
        }
        return *this;
    }

    DigitalIO& DigitalIO::input_pullup(void){
        if(this->_pin < 8u){
            DDRD &= ~(1<<this->_pin);
            this->set_high();
        }else if(this->_pin < 14u){
            DDRB &= ~(1<<(this->_pin - 8u));
            this->set_high();
        }else if(this->_pin < 20u){
            DDRC &= ~(1<<(this->_pin - 14u));
            this->set_high();
        }
        return *this;
    }

    DigitalIO& DigitalIO::set_high(void){
        if(this->_pin < 8U){
            PORTD |= (1<<this->_pin);
        }else if(this->_pin < 14U){
            PORTB |= (1<<(this->_pin - 8u));
        }else if(this->_pin < 20u){
            PORTC |= (1<<(this->_pin - 14u));
        }
        return *this;
    }

    DigitalIO& DigitalIO::set_low(void){
        if(this->_pin < 8u){
            PORTD &= ~(1<<this->_pin);
        }else if(this->_pin < 14u){
            PORTB &= ~(1<<(this->_pin - 8u));
        }else if(this->_pin < 20u){
            PORTC &= ~(1<<(this->_pin - 14u));
        }
        return *this;
    }

    DigitalIO& DigitalIO::toggle(void){
        if(this->_pin < 8U){
            PORTD ^= (1<<this->_pin);
        }else if(this->_pin < 14U){
            PORTB ^= (1<<(this->_pin - 8u));
        }else if(this->_pin < 20u){
            PORTC ^= (1<<(this->_pin - 14u));
        }
        return *this;
    }

    bool DigitalIO::read(void){
        if(this->_pin < 8u){
            return (PIND & (1<<this->_pin));
        }else if(this->_pin < 14u){
            return (PINB & (1<<(this->_pin-8u)));
        }else if(this->_pin < 20u){
            return (PINC & (1<<(this->_pin-14u)));
        }
        return false;
    }
    

}