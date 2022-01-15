#include <display7seg.hpp>
#include <avr/pgmspace.h>

namespace display7seg{
    const uint8_t LUT_converter[] PROGMEM = {0b11111100, 0b01100000, 0b11011010, 0b11110010, 0b01100110, 0b10110110, 0b10111110, 0b11100000,
        0b11111110, 0b11100110};

    Display& Display::init(){
        for(auto i : this->_segments){
            i.output().set_low();
        }
        for(auto i : this->_digits){
            i.output().set_high();
        }
        return *this;
    }

    Display& Display::write(uint8_t value, uint8_t posi){
        if(value > 17 || posi > 3) return *this;
        this->_number[posi] = value;
        return *this;
    }

    Display& Display::write(uint16_t value){
        if(value > 9999u) return *this;
        uint8_t M = (value/1000)%10;
        uint8_t C = (value/100)%10;
        uint8_t D = (value/10)%10;
        uint8_t U = (value/1)%10;
        this->write(M, 0);
        this->write(C, 1);
        this->write(D, 2);
        this->write(U, 3);
        return *this;
    }

    Display& Display::update(){
        for(auto dig : this->_digits){
            dig.set_low();
        }
        this->_digits[disp].set_high();
        this->send(pgm_read_byte_near(LUT_converter + this->_number[disp]));
        this->disp++;
        if(this->disp > 3) this->disp = 0;
        return *this;
    }

    void Display::send(uint8_t value){
        for(auto seg : this->_segments){
            if(value & 0x80){
                seg.set_low();
            }else{
                seg.set_high();
            }
            value <<= 1;
        }
    }
}
