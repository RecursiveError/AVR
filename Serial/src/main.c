#include <Arduino.h>
#include "Serial.h"

//a função delay não esta funcionando na avr-libc usado
void _delay();

const char* msg = "hello world";

void main(){

  pinMode(4, OUTPUT);
  serial_init(9600);
  
  for(;;){
    for(int i = 0; i<12; i++){
      serial_send(msg[i]);
    }
    serial_flush();
  
    digitalWrite(4, HIGH);
    _delay(50);
    digitalWrite(4,LOW);
    _delay(50);
  }
}


void _delay(long int ms){
  volatile unsigned long int i;
  for(i=0; i<((ms*1000)*2); i++);
}