#include "disp.h"
#include "IO.h"

//tempo aleatorio apenas para teste
unsigned long int count = 0xFFFF;
void main(){
  pinMode(12, OUTPUT);
  dispInit();
  for(;;){
    //para de atualizar  display apos chegar ao 0000
    dispWrite(1, 0);
    dispWrite(2, (count/5000)% 10);
    dispWrite(3, (count/500)% 10);
    dispWrite(4, (count/50)% 10);
    dispUpdate(); 
    if(!((count /  5000) % 10)){
      dispWrite(1, 0);
      dispWrite(2, 0);
      dispWrite(3, 0);
      dispWrite(4, 0);
      dispUpdate();
      for(;;){
        digitalWrite(8, LOW);
        digitalWrite(9, LOW);
        digitalWrite(10, LOW);
        digitalWrite(11, LOW);
        digitalWrite(12, LOW);
        //loop maior pois com menos funções usam menos ciclos
        for(unsigned volatile long i = 0; i < 100000; i++);
        digitalWrite(8, 1);
        digitalWrite(9, 1);
        digitalWrite(10, 1);
        digitalWrite(11, 1);
        digitalWrite(12, 1);
        for(unsigned volatile long i = 0; i < 100000; i++);
      }
    }
    for(unsigned volatile long i = 0; i < 500; i++);
    count--;
  }
}