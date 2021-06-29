/*
Programa: Interrupt
Autor: RecursiveError

Programa simples para lidar com interrupções externas

*/

#include <avr/io.h>
#include <avr/interrupt.h>

ISR(INT1_vect);

int main(){
  DDRD = (1<<PD4);
  PORTD = 0xFF;
  EICRA = (1<<ISC11); //ativa a interrupção na decida 
  EIMSK = (1<<INT1);//Habilita a interrupção externa
  sei();

  for(;;);
  return 0;
}

ISR(INT1_vect){
  PORTD ^= (1<<PD4);
}