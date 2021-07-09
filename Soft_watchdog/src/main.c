/*
Autor:RecursiveError
----------------------------------------------------------
Programa para testar software watchdog
liga um led e gera um deadlock
apos 3 resets o watchdog liga o led de erro e trava a execução 
*/
#include <avr/io.h>
#include <avr/delay.h>
#include "soft_wtd.h"

int main(void){
    DDRD  = (1<<PORT3);
    PORTD = (1<<PORT3);
    _delay_ms(500);
    PORTD &= ~(1<<PORT3);
    _delay_ms(500);
    watchdog_init();
    for(;;){
        watchdog_feed();
        for(;;);//gera um deadlock, apos 1ms o arduino reseta sozinho
    }
    return 0;
}