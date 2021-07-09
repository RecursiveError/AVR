/*
Autor:RecursiveError
Programa:soft_wtd
------------------------------------------------------
Um simples watchdog por software q ativa a cada ~1ms

-------AVISO--------
esse programa utiliza o TC0 e habilita a chave global de interrupção 
*/

#include<avr/io.h>
#include<avr/delay.h>
#include<avr/interrupt.h>

// aumenta em 1 para cada vez que o watchdog  timer ocorre
volatile unsigned char flag;

//pula para o endereço 0
void(*RESET)(void) = 0; 

ISR(TIMER0_OVF_vect){
    //desliga o timer e reseta
    flag++;
    TIMSK1 = 0X00;
    TCCR0B = 0X00;   
    RESET();
}


//inicia o watchdog
void watchdog_init(void){
    sei();
    TCCR0A = 0X00;
    TCCR0B = (1<<CS01) | (1<<CS00);
    TIMSK0 = (1<<TOIE0);
    return;
}


//reseta o timer evitando o reset
void watchdog_feed(){
    TCNT0 = 0X00;
    return;
}

//desabilita o timer
//NÃO DESABILITA A INTERRUPÇÃO GLOBAL
void watchdog_disable(void){
    TCCR0B = 0X00;
    TIMSK0 = 0X00;
    return; 
}

unsigned char get_flag(void){
    return flag;
}