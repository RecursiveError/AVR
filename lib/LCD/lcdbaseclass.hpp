#include <stdint.h>

#define _LCD_8BITS_ 1
#define _LCD_4BITS_ 2

namespace liquidcrystal{
    class lcdbaseclass{
        public:
            virtual void set_pins() = 0;
            virtual void send(uint8_t value, bool std) = 0;
            virtual void set_cursor(uint8_t line, uint8_t cols) = 0;
            virtual void pulse() = 0;
    };
}