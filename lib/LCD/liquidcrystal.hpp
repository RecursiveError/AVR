/*
Programa: liquidcrystal.h
Autor: RecursiveError

header para gerenciar LCDs
*/
#ifndef _LIQUIDCRYSTAL_HPP
#define _LIQUIDCRYSTAL_HPP

#include <stdint.h>
#include <util/delay.h>
#include <WString.h>
#include "unique_ptr.hpp"
#include "lcd_package.hpp"

#define _LCD_8BITS_ 1
#define _LCD_4BITS_ 2

namespace liquidcrystal{
    class Liquidcrystal{
        public:
            template <class lcd_config>
            Liquidcrystal(lcd_config Tconfig){
                //lcd_type = fakestd::make_uniq<lcd_config>(Tconfig);
                lcd_type = new lcd_config(Tconfig);
            }

            Liquidcrystal& init(uint8_t cols, uint8_t line);

            Liquidcrystal& write(char value);

            Liquidcrystal& write(int value);

            Liquidcrystal& write(String value);

            Liquidcrystal& config(uint8_t flag);

            Liquidcrystal& set_cursor(uint8_t line, uint8_t cols);
        private:
            uint8_t _cols{0}, _line{0};
            //fakestd::uniq_ptr<lcdbaseclass> lcd_type;
            lcdbaseclass* lcd_type;
    };
}
#endif
