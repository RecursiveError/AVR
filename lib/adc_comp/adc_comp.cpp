#include "adc_comp.hpp"
#include "IO.hpp"
#include <avr/io.h>

namespace comparator{
    Adc_comparator& Adc_comparator::set_Nref(int pin){
        if(pin != DEFULT_COMP_PIN){
            ADCSRB |= ACME;
            ADCSRA |= (0<<ADEN);
            ADMUX |= pin > 7 ? 0 : pin & 0x0F;
        }else{
            ADCSRB |= (0<<ACME);
        } 
        return *this;
    }

    Adc_comparator& Adc_comparator::set_Pref(Pref REF){
        ACSR |= (REF<<ACBG);
        return *this;
    }

    Adc_comparator& Adc_comparator::set_event(mode mode, handler_func callback){
        ACSR |= mode & 0x02;
        digitalIO::DigitalIO(7).input_pullup();
        digitalIO::DigitalIO(6).input_pullup();
        interrupt::handler.set_handle(ANALOG_COMP_vect_num, callback);
        interrupt::handler.enable();
        return *this;
    }

    bool Adc_comparator::get_output(){
        return ACSR & (1<<ACO);
    }

    bool Adc_comparator::get_flag(){
        return ACSR & (1<<ACI);
    }

    Adc_comparator& Adc_comparator::enable(){
        DIDR1 = 0X3;
        ACSR |= (1<<ACIE);
        return *this;
    }

    Adc_comparator& Adc_comparator::disable(){
        DIDR1 = 0;
        ACSR |= (0<<ACIE);
        return *this;
    }    
}