/*
Autor:RecursiveError
Programa: Watchdog.c

Uma implementação basica do watchdog do atmel328p
--------AVISO---------
AS FUNÇÃES DESSE PROGRAMA DESATIVAM AS INTERRUPÇÕES PARA AVITAR ERROS EM SUA INICIALIZAÇÃO
*/

#include<avr/interrupt.h>
#include<avr/io.h>
#include<avr/wdt.h>

//inica o watchdog
//Recebe um numero inteiro até 7 para definir o prescaler
//consulte o manual do atmel328p para mais informações dessa configuração
void init_watchdog(char prescaler){
    cli();

    if(prescaler>7){
        WDTCSR |= (0X0F & prescaler);
    }else{
        WDTCSR |= 0x00;
    }
    MCUSR &= ~(1<<WDRF);//limpa a flag do wtd
    WDTCSR |= (1<<WDE);//modo de inicialização
    sei();
    return;
}

//muda o prescaler
void change_prescaler(char prescaler){
    cli();
    wdt_reset();
    MCUSR &= ~(1<<WDRF);
    if(prescaler>7){
        WDTCSR |= (0X0F & prescaler);
    }else{
        WDTCSR |= 0x00;
    }
    return;
}



void feed_watchdog(void){
    wdt_reset();
    return;
}
