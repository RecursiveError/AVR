/*
Programa: Timers
Autor: RecursiveError
Programa simples para testar  Timers do Atmel328p
*/
#include <avr/io.h>
#include <avr/interrupt.h>
#include <adc.h>

//OCRxA COMPARAÇÃO
//TCNTx contador
//TCCRxA MODO DE OPERAÇÃO
//TTCRxB CONFIGURAÇÃO
//TIMSKx config de interrupção

ISR(TIMER1_COMPA_vect){
    TCNT1 = 0; //REINICIA O TIMER
    PORTD ^= (1<<PD4);

}

int main(){
    int R;
    adc_init();
    DDRD |= (1<<PD4);
    TCCR1A = 0; //Modo Normal
    TCCR1B = 0x03;// prescaler = 64
    TCNT1 = 0; //inicia do 0
    OCR1A = 30000;
    TIMSK1 |= (1<<OCIE0A); // Interrupção na comparação
    sei(); //habilita a chave de interrupção global
    for(;;){
       R = adc_read(5);
       OCR1A = (257*R);
    }
    return 0;
}