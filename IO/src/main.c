/*
//Autor: RecursiveError
crie um programa q realize a leitura de 3 chaves na porta D nos bit 1, 2 e 3.
(Ja criado na IO.h)
Em seguida , este programa deverá acender uma quantidade de leds correspondente ao
somatório dos numeros das chaves
*/


#include "IO.h"



int soma = 1;

void _setup(){
    soma = 0;
   pinMode(2, INPUT);
   pinMode(3, INPUT);
   pinMode(7, INPUT);
   for(int i = 8; i < 14; i++){
       pinMode(i, OUTPUT);
   }
}

void _loop(){
    if(digitalRead(2)){
        soma += 1;
    }

    if(digitalRead(3)){
        soma += 2;
    }

    if(digitalRead(7)){
        soma += 3;
    }

    for(int i = 8; i<14; i++){
        if(soma > 0){
            digitalWrite(i, HIGH);
            soma--;
        }else{
            digitalWrite(i, LOW);
        }

    }
}




int main(void){
    _setup();
    
    for(;;){
        _loop();
    }

return 0;
}