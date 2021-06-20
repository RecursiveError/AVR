/*
Programa: Timers.c
Autor:RecursiveError
DATA: 19/06/2021
Objetivo: Programa para gerenciar um tempo minimo para um ciclo do loop principal
podendo ir de ~1ms até ~1s

*/



#include <avr/io.h>
#include <Timers.h>

//valor de estouro do timer
#define TIMER_MAX 65500

//configura o timer
void timer_init(void){
    TCCR1A |= 0x00;//MODO NORMAL
    TCCR1B |= 0x00;//timer desligado
    TCNT1 = 0;// reseta o contador
    return;
}

/*
Liga o timer e inicia o contador
valor por unidade ~1ms
MAXIMO: 1000 ou 1s
Retorna 1 caso o valor passe do limite
*/ 
int timer_start(unsigned int value){
    if(value<1000){
        return 1;
    }else{
        TCCR1B |= 0x00;//desliga o timer para manipulação
        TCNT1 = (int)(TIMER_MAX - (65.5*value));//valor aproximado
        TCCR1B |= 0X04;//liga o timer com prescaler de 256
    }
    return 0;
}

int timer_read(void){
    return TCNT1;
}

//Retorna o estado do timer
//retorna 1 caso a contagem tenha acabado e desliga o timer
//retorna 0 se a contagem ainda não acabou
int timer_finished(void){
    if(TCNT1>=TIMER_MAX){
        TCCR1B |= 0x00;// desliga o timer
        return 1;
    }else{
        return 0;
    }
}


//criar uma contagem para delay
void timer_delay(unsigned int delay){
    timer_start(delay);
    while(!timer_finished());
    return;
}

//espera a contagem acabar
void timer_wait(void){
    while(TCNT1<65500);
    TCCR1B |= 0x00; //desliga o timer
    return; 
}