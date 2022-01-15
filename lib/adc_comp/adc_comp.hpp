#ifndef ADC_COMP_HPP
#define ADC_COMP_HPP

#include "interrupt.hpp"

#define DEFULT_COMP_PIN 0xFF
namespace comparator{
    enum mode{
        ANY,
        NONE,
        DOWN,
        UP 
    };

    enum Pref {
        AIN0,
        INTERNAL
    };

    class Adc_comparator{
        public:
            Adc_comparator& enable();
            Adc_comparator& disable();
            Adc_comparator& set_Nref(int adc_pin = DEFULT_COMP_PIN);
            Adc_comparator& set_Pref(Pref REF = AIN0);
            Adc_comparator& set_event(mode mode, handler_func callback = nullptr);
            bool get_output();
            bool get_flag();
    };
}

#endif