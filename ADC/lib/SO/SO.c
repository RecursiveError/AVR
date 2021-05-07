/*
Autor: RecursiveError

lib para expansão de portas OUTPUT usando o shift-Register 74hc595
*/
#include "IO.h"

#define DATA 2
#define DCLOCK 4
#define EN 3

//inicia o 74hc595
void so_init(){
    pinMode(DATA, OUTPUT);
    pinMode(DCLOCK, OUTPUT);
    pinMode(EN, OUTPUT);
}

//gera clock no pino de data
void pulse_data(){
    digitalWrite(DCLOCK, HIGH);
    digitalWrite(DCLOCK, LOW);
}

//gera clock no pino EN
void pulse_en(){
    digitalWrite(EN, HIGH);
    digitalWrite(EN, LOW);
}


//envias as informaçãos bit a bit para o CI
void so_write(char value){
    for(char i = 0; i < 8; i++){
        digitalWrite(DATA, value & 0x80);
        pulse_data();
        value <<= 1;
    }
    pulse_en();
}
