//Autor:RecursiveError
//DATA:19/06/2021
//Programa para testa a lib Timers.h

#include <avr/io.h>
#include <Timers.h>

int main(void){
  timer_init();
  DDRD |= (1<<PD4);//liga o pino 4 como output

  for(;;){
    timer_start(1000);
    PORTD ^= (1<<PD4);//inverte o estado do pino 4
    timer_wait();
  }
  return 0;
}