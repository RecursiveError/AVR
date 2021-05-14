//Autor: RecursiveError
//Programa para testa a lib de PWM
#include <avr/io.h>
#include <avr/delay.h>
#include "pwm.h"
int main(){
    int i = 0;
    pwm_init();
    for(;;){
        for(; i< 255; i++){
            set_duty(6,i);
            _delay_ms(7);
        }
        _delay_ms(7);
        for(; i>0; i--){
            set_duty(6,i);
            _delay_ms(7);
        }
        _delay_ms(7);
    }
    return 0;
}

