/*
Programa: interrupt
Autor: RecursiveError

Programa que mapeia as interrupções
*/
#ifndef _INTERRUPT_HPP
#define _INTERRUPT_HPP

#include "avr/interrupt.h"
#include <event_handler.hpp>

namespace interrupt {
extern Event_handler handler;
}

//QUANTIDADE DE INTERRUPÇÕES
#define _INT_VEC_ 26
//MAPA DAS INTERRUPÇÕES

ISR(INT0_vect);

ISR(INT1_vect);

ISR(PCINT0_vect);

ISR(PCINT1_vect);

ISR(PCINT2_vect);

ISR(WDT_vect);

ISR(TIMER2_COMPA_vect);

ISR(TIMER2_COMPB_vect);

ISR(TIMER2_OVF_vect);

ISR(TIMER1_CAPT_vect);

ISR(TIMER1_COMPA_vect);

ISR(TIMER1_COMPB_vect);

ISR(TIMER1_OVF_vect);

ISR(TIMER0_COMPA_vect);

ISR(TIMER0_COMPB_vect);

ISR(TIMER0_OVF_vect);

ISR(ADC_vect);

ISR(ANALOG_COMP_vect);
#endif