/*
Autor: RecursiveError
programa:keypad

programa para a leitura do teclado matricial
*/

#include "IO.h"
#include "keypad.h"

#define linhas 4
//valor atual do botão
static unsigned int key;

//retorna o valor do botão
unsigned int keypad_read(){
    return key;
}

/*
lê o valor e faz o debounce
LEITURA: varre as colunas do teclado matricial e retorna o valor na posição N bit do "key"
    Ex: coluna 1 botão 1  = 0b01
        coluna 2 botão 1  = 0b10000
        ...
DEBOUNCE: atualiza o valor de "key" apos a estabilizar os ruidos do botão
    (usa delay externo para o tempo)
*/
void keypad_debounce(){
    static unsigned char tempo;
    static unsigned int oldValue;
    static unsigned int newValue;
    newValue = 0;

    for(int i = 0; i<linhas; i++){
        digitalWrite(i+2, HIGH);

        if(digitalRead(6)){
            bitSet(newValue, i);
        }
        if(digitalRead(7)){
            bitSet(newValue, (i+4));
        }
        digitalWrite(i+2, LOW);
    }
    if(oldValue == newValue){
        tempo--;
    }else{
        tempo = 4;
        oldValue = newValue;
    }
    if(tempo == 0){
        key = oldValue;
    }
}


//inicia o teclado
void keypad_init(){
    for(int i = 2; i < 6; i++){
        pinMode(i, OUTPUT);
    }
    pinMode(6, INPUT);
    pinMode(7, INPUT);
}



