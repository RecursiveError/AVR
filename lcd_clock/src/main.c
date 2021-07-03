/*
---------------------------------------------
Programa:lcd_clock
Autor:RecursiveError
Programa que usa um timer para gerar uma interrupção a cada milisegundo
Incrementa "tick" a cada interrupção
Exibe o valor de "tick" no display
---------------------------------------------

Esse programa também serve como exemplo dos problemas em ter delays nas bibliotecas de display LCD
presentes na maioria das plataformas,esse tema será abordado no projeto final dos topicos:
Timers
Interrupções 
*/
#include <avr/interrupt.h>
#include <avr/io.h>
#include "lcd.h"
#include "SO.h"

unsigned long int tick = 0;

ISR(TIMER0_OVF_vect){
	tick++;
}


int main(){
	so_init();
	lcd_init();
	TCCR0A = 0x00;//timer em modo normal
	TCCR0B = 0x03;//prescaler de 64
	TIMSK0 = (1<<TOIE0);//interrupção no overflow do timer
	sei();
	for(;;){
		lcd_set_position(0,0);
		lcd_send_number(tick);
	}
	return 0;
}