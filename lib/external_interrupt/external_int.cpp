#include "external_int.hpp"
#include <interrupt.hpp>
#include "IO.hpp"


namespace external_int{
    External_int& External_int::event_on(int pin, int mode, handler_func callback){
        switch(pin){
            case _INT0_:
                EICRA |= mode;
                EIMSK |= 1<<0;
                digitalIO::DigitalIO(2).input_pullup();
                interrupt::handler.set_handle(INT0_vect_num, callback);
                break;
            case _INT1_:
                EICRA |= (mode <<= 2);
                EIMSK |= 1<<1;
                digitalIO::DigitalIO(3).input_pullup();
                interrupt::handler.set_handle(INT1_vect_num, callback);
                break;
        }
        interrupt::handler.enable();
        return *this;
    }

    External_int& External_int::disable(int pin){
        switch(pin){
            case _INT0_:
                EIMSK |= 0<<0;
                break;
            case _INT1_:
                EIMSK |= 0<<1;
                break;
        }
        return *this;
    }
}