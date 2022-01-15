/*
Programa: Display7seg
Autor: RecursiveError

programa para trabahlar com displays de 7 segmentos 4 digitos
*/

#ifndef _7_SEG_DISP_HPP
#define _7_SEG_DISP_HPP
#include <stdint.h>
#include "IO.hpp"


namespace display7seg{
    class Display {
        private:
            digitalIO::DigitalIO _segments[7];
            digitalIO::DigitalIO _digits[4];
            uint8_t _number[5]{0,0,0,0};
            uint8_t disp{0};
            void send(uint8_t value);
            
        public:
            Display(uint8_t A, uint8_t B, uint8_t C, uint8_t D, uint8_t E, uint8_t F, uint8_t G,
                uint8_t digit1, uint8_t digit2, uint8_t digit3, uint8_t digit4):
            _segments{A,B,C,D,E,F,G},
            _digits{digit1, digit2, digit3, digit4}
            {}
            Display& init();
            Display& write(uint8_t value, uint8_t posi);
            Display& write(uint16_t value);
            Display& update(); 
    };
}

#endif