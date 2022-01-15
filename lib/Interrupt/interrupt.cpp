#include "interrupt.hpp"


namespace interrupt {
Event_handler handler;
}

ISR(INT0_vect){
    exec(interrupt::handler, INT0_vect_num);
}

ISR(INT1_vect){
    exec(interrupt::handler,INT1_vect_num);
}

ISR(PCINT0_vect){
    exec(interrupt::handler,PCINT0_vect_num);
}

ISR(PCINT1_vect){
    exec(interrupt::handler,PCINT1_vect_num);
}

ISR(PCINT2_vect){
    exec(interrupt::handler,PCINT2_vect_num);
}

ISR(WDT_vect){
    exec(interrupt::handler,WDT_vect_num);
}

ISR(TIMER2_COMPA_vect){
    exec(interrupt::handler,TIMER2_COMPA_vect_num);
}

ISR(TIMER2_COMPB_vect){
    exec(interrupt::handler,TIMER2_COMPB_vect_num);
}

ISR(TIMER2_OVF_vect){
    exec(interrupt::handler,TIMER2_OVF_vect_num);
}

ISR(TIMER1_CAPT_vect){
    exec(interrupt::handler,TIMER1_CAPT_vect_num);
}

ISR(TIMER1_COMPA_vect){
    exec(interrupt::handler,TIMER1_COMPA_vect_num);
}

ISR(TIMER1_COMPB_vect){
    exec(interrupt::handler,TIMER1_COMPB_vect_num);
}

ISR(TIMER1_OVF_vect){
    exec(interrupt::handler, TIMER1_OVF_vect_num);
}

ISR(TIMER0_COMPA_vect){
    exec(interrupt::handler,TIMER0_COMPA_vect_num);
}

ISR(TIMER0_COMPB_vect){
    exec(interrupt::handler,TIMER0_COMPB_vect_num);
}

ISR(TIMER0_OVF_vect){
    exec(interrupt::handler, TIMER0_OVF_vect_num);
}

ISR(ADC_vect){
    exec(interrupt::handler,ADC_vect_num);
}

ISR(ANALOG_COMP_vect){
    exec(interrupt::handler,ANALOG_COMP_vect_num);
}