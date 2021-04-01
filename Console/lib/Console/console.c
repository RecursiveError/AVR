/*
Autor: RecursiveError
Programa: console
lib para o tratamento do display LCD
*/

#include "lcd.h"

//define as opções para manipulação
#define LCD_LINES  2
#define LCD_COLS   16
#define BUFF_LINES 5
#define BUFF_COLS  (LCD_COLS+1)

char buff[BUFF_LINES][BUFF_COLS]; 
int line; //linha atual
int col; //coluna atual

//inicia o console, todas as linhas do buffer são apagadas 
void console_init(){
    int i,j;
    lcd_init();
    for(i = 0; i<BUFF_LINES; i++){
        for(j = 0; j<BUFF_COLS; j++){
            buff[i][j]= '\0';
        }
    }
    line = (BUFF_LINES - LCD_LINES);
    col = 0;
}

//move os valores para cima no buffer
void new_line(){
    int l,c;
    for(l = 1; l<BUFF_LINES; l++){
        for(c = 0; c<BUFF_COLS; c++){
            buff[l - 1][c] = buff[l][c];
        }
    }
    for(c = 0; c<BUFF_COLS; c++){
        buff[BUFF_LINES -1][c] = '\0';
    }
}
//envia o buffer para o LCD
void console_update(){
    int i,j;
    lcd_command(0x01);
    for(i = 0; i<LCD_LINES; i++){
        //escreve em cada linha do display
        lcd_set_position(i,0);
        for(j = 0; j < BUFF_COLS; j++){
            if((buff[line+i][j] == '\0')){
                break;
            }else{
                lcd_send_char(buff[line+i][j]);
            }
        }
    }
}

//salva as informações no buffer
void console_print(char* vet){
    int currentpos = 0;
    //roda ate a string acabar
    while(vet[currentpos] != '\0'){
        //pula linha caso haja um \n
        if(vet[currentpos] == '\n'){
            buff[BUFF_LINES -1][col] = '\0';
            col = 0;
            new_line(); 
        //caso seja uma letra    
        }else{
            buff[BUFF_LINES -1][col] = vet[currentpos];
            col++;
            //se passa o total de colunas pula uma linha
            if(col >= (BUFF_COLS-1)){
                buff[BUFF_LINES -1][BUFF_COLS -1] = '\0';
                col = 0;
                new_line();
            }
        }

        currentpos++;
    }
    //armazena o fim da linha no buffer 
    buff[BUFF_LINES-1][col] = vet[currentpos];
}

//move entre as linhas do buffer
// 1 avança uma linha 
//-1 volta uma linha
void console_move_line(int move){
    if(move<0){
        if(line > 0){
            line--;
        }
    }
    if(move>0){
        if(line < BUFF_LINES - LCD_LINES){
            line++;
        }
    }
}