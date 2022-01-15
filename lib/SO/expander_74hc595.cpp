/*
Programa: Expander_74hc595
Autor: RecursiveError

biblioteca para expansão de portas OUTPUT usando o shift-Register 74hc595
*/
#include <stdint.h>

#include "IO.hpp"
#include "expander_74hc595.hpp"

using namespace digitalIO;

namespace serial_output{
    Expander_74hc595& Expander_74hc595::init(void){
        this->_data.output().set_low();
        this->_clock.output().set_low();
        this->_enable.output().set_low();        
        return *this;
    }

    Expander_74hc595& Expander_74hc595::send(uint8_t value){
        for(char i = 0; i < 8; i++){
            if(value & 0x80) this->_data.set_high();
            else this->_data.set_low();
            this->pulse_clock();
            value <<= 1;
        }
        this->pulse_enable();
        return *this;
    }

    void Expander_74hc595::pulse_clock(void){
        this->_clock.set_high().set_low();
    }

    void Expander_74hc595::pulse_enable(void){
        this->_enable.set_high().set_low();
    }
}

