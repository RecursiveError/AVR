/*
Autor: RecursiveError

programa para teste da lib "kaypad"

*NOTA:
    O uso do teclado muda de acordo com o objetivo,
    por ser um teste esse programa não trata de forma eficinte a leitura e exibição
*/

#include "lcd.h"
#include "SO.h"
#include "IO.h"
#include "keypad.h"

//comando para limpar o LCD
#define CLEAR 0X01

void limpa();

//representa o valor de cada tecla
const char valores[] = {'1','4','7', '*', '2', '5', '8', '0'};

unsigned int valor;
unsigned int valorAnterior;


int main(){
    //iniciação
    so_init();
    keypad_init();
    lcd_init();
    lcd_set_position(0,0);
    for(;;){
        keypad_debounce();
        valor = keypad_read();

        //executa apenas se o estado do botão mudar
        if(valor != valorAnterior){
            for(int i = 0 ; i < 8; i++){
                if(bitTst(valor, i)){
                    if(i == 3){
                        limpa();
                        continue;
                    }
                    lcd_send_char(valores[i]);
                }
            }
            valorAnterior = valor;
        }
    }
    return 0;
}

//limpa o display e volta para a posição 0/0
void limpa(){
    lcd_command(CLEAR);
    lcd_set_position(0,0);
}
