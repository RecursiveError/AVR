/*
Programa: Expander_74hc595
Autor: RecursiveError

biblioteca para expansão de portas OUTPUT usando o shift-Register 74hc595
*/

#ifndef _EXPANDER_74hc595_H
#define _EXPANDER_74hc595_H

#include <stdint.h>
#include "IO.hpp"

namespace serial_output{
    class Expander_74hc595{
        public:
            Expander_74hc595() = delete;
            Expander_74hc595(uint8_t data, uint8_t clock, uint8_t enable):
                _data{data}, 
                _clock{clock},
                _enable{enable}
                {}

            Expander_74hc595& init(void);
            Expander_74hc595& send(uint8_t value);
        private:
            digitalIO::DigitalIO _data, _clock, _enable;
            void pulse_clock(void);
            void pulse_enable(void);
    };
}


#endif