/*
Programa: liquidcrystal_expander_595.h
Autor: RecursiveError

biblioteca para o displays compativeis com o HD44780 usando o shift-register 74hc595

essa biblioteca também é compatível com controladores semelhantes ao shift-register 74hc595
*/

#ifndef _LCD_595_H
#define _LCD_595_H


#include <stdint.h>
#include "expander_74hc595.hpp"
#include "lcdbaseclass.hpp"
#include "IO.hpp"
namespace liquidcrystal{

    //----------------------------Lcd595------------------
    class Lcd595 : public lcdbaseclass{
        public:
            Lcd595(uint8_t data, uint8_t clock, uint8_t c_enable, uint8_t register_select, uint8_t lcd_enable) :
                controller{data, clock, c_enable},
                register_select{register_select},
                enable{lcd_enable}
            {}
            
            void set_cursor(uint8_t line, uint8_t cols) override;
            void pulse() override;
            void set_pins() override;
            void send(uint8_t value, bool std) override;
        private:
            serial_output::Expander_74hc595 controller;
            digitalIO::DigitalIO register_select, enable;
    };

    //----------------------------Lcd595------------------

    //--------------------------Lcd_4bits-----------------
    class Lcd_4bits : public lcdbaseclass{
        public:
        Lcd_4bits(uint8_t RS, uint8_t EN, uint8_t D0, uint8_t D1,uint8_t D2, uint8_t D3) :
                register_select{RS},
                enable{EN},
                pins{D0, D1, D2, D3}
            {}

            void send(uint8_t value, bool std) override;
            void set_cursor(uint8_t line, uint8_t cols) override;
            void pulse() override;
            void set_pins() override;
        private:
            digitalIO::DigitalIO register_select{0}, enable{0};
            digitalIO::DigitalIO pins[4];
            void send_nibble(uint8_t value);

    };

    //--------------------------Lcd_4bits-----------------

    //---------------------lcd2EN_4Bbits------------------
    class Lcd2EN_4bits : public lcdbaseclass{
        public:
            Lcd2EN_4bits(uint8_t RS, uint8_t EN1, uint8_t EN2, uint8_t D0, uint8_t D1,uint8_t D2, uint8_t D3) :
                _high{RS, EN1, D0, D1, D2 ,D3},
                _low{RS, EN2, D0, D1, D2 ,D3}
            {}

            void set_cursor(uint8_t line, uint8_t cols) override;
            void pulse() override;
            void set_pins() override;
            void send(uint8_t value, bool std) override;
        private:
            Lcd_4bits _high, _low;
            Lcd_4bits* _corrent{&_high};
            digitalIO::DigitalIO register_select{0}, enable{0};
    };

    //---------------------lcd2EN_4Bbits------------------
}

#endif