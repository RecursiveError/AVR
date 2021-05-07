/*
Programa: ADC
Autor: RecursiveError
Programa para leitura das portas adc
*/
#include <avr/io.h>
#include "IO.h"

void adc_init(){
    bitSet(ADMUX, ADLAR);//Referencia no pino AVCC
    bitSet(ADMUX, REFS0);// Resolução de 8bits
    //Prescaler 128
    bitSet(ADCSRA, ADPS0);
    bitSet(ADCSRA, ADPS1);
    bitSet(ADCSRA, ADPS2);
    //habilita o ADC
    bitSet(ADCSRA, ADEN);
    DDRC = 0X00;
}

unsigned int adc_read(unsigned char canal){
    ADMUX = (ADMUX & 0xF0) | (canal & 0x0F); //apenas segurança
    bitSet(ADCSRA, ADSC);
    while(bitTst(ADCSRA, ADSC));
    return ADCH;
}

