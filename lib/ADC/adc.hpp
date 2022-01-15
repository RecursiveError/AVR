/**
 * Programa: ADC
 * Autor: RecursiveError
 * lib para trabalhar com portas adc
 **/
#ifndef ADC_HPP
#define ADC_HPP
#include <stdint.h>
#include "interrupt.hpp"

namespace adc {
    enum Tref{
        OFF,
        AVCC,
        RESERVED,
        INTERNAL
    };

    enum channel{
        ADC0,
        ADC1,
        ADC2,
        ADC3,
        ADC4,
        ADC5,
        ADC6,
        ADC7,
        TEMP
    };

    enum Ftrigger{
        NORMAL,
        ADC_COMP,
        INT_0,
        COMPA_TC0,
        OVF_TC0,
        COMPB_TC1,
        OVF_TC1,
        EVENT_TC1
    };

    class Adc{
        public:
            Adc(Tref ref, uint8_t prescaler, bool adjust);
            Adc& enable();
            Adc& disable();
            Adc& trigger(Ftrigger trigger);
            Adc& start();
            Adc& set_event(handler_func callback);
            uint16_t read(channel adc_pin);
            bool get_flag();
            Adc& operator()(Tref ref, uint8_t prescaler, bool adjust);
        private:
            void configure(Tref ref, uint8_t prescaler, bool adjust);
    };
}

#endif

 