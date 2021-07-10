/*
Autor: RecursiveError
Teste do watchdog do atmel328p
*/

#include <avr/io.h>
#include <avr/delay.h>
#include "hard_watchdog.h"

int main(){
  DDRD = (1<<PORTD3);
  PORTD = (1<<PORTD3);
  _delay_ms(500);
  PORTD &= ~(1<<PORTD3);
  _delay_ms(500);
  init_watchdog(0);
  for(;;); //deadlock
}