/*
LCD.C
Autor: RecursiveError

lib para display lcd 16x2 compativel com HD44780
Adaptada para o Shift-Register 74HC595
*/

#include "lcd.h" 
#include "IO.h"
#include "SO.h"

//delay em micro segundos(tempo aproximado)
void lcd_delay_micro(int time){
    volatile int i;
    for(i=0; i<(time*2); i++);
}

//delay em milli segundos
void lcd_delay_millis(int time){
    volatile int i;
    for(i=0; i<time; i++) lcd_delay_micro(1000);

}

//envia 4 bits para o display
void push_nibble(char value, char rs){
    so_write(value);
    digitalWrite(RS, rs);
    lcd_pulse();    
}

//envia 8 bits em 2 pacotes de 4 bits
void push_byte(char value, char rs){
    digitalWrite(RS, rs);
    so_write(value >> 4);
    lcd_pulse();
    so_write(value & 0x0F);
    lcd_pulse();
}

//gera clock no pino EN do display
void lcd_pulse(){
    digitalWrite(EN, HIGH);
    lcd_delay_micro(5);
    digitalWrite(EN, LOW);
    lcd_delay_micro(5);
}


void lcd_send_char(char value){
    push_byte(value, HIGH);
    lcd_delay_micro(80);
}

void lcd_command(char value){
    push_byte(value, LOW);
    lcd_delay_millis(2);

}

void lcd_send_string(char string[]){
    int i = 0;
    while(string[i] != '\0'){
        lcd_send_char(string[i]);
        i++;
    }
}

void lcd_send_number(int value){
    int i = 10000;
    while(i>0){
        lcd_send_char((value/i) % 10 + 48);
        i /= 10;
    }
}


//define a posição do cursor
void lcd_set_position(int line, int col){
    if(line == 0){
        lcd_command(0x80+col);
    }
    if(line == 1){
        lcd_command(0xC0+col);
    }    
}

//inicia o display
void lcd_init(){
    pinMode(RS, OUTPUT);
    pinMode(EN, OUTPUT);
     
    lcd_delay_millis(15);
    //ESTADO DA COMUNICAÇÃO É INCERTO
    push_nibble(0X3, LOW);
    lcd_delay_millis(5);
    push_nibble(0X3, LOW);
    lcd_delay_micro(160);
    push_nibble(0X3, LOW);//ESTADO DA COMUNICAÇÃO É 8BITS

    //MUDANDO PARA 4BITS
    lcd_delay_micro(160);
    push_nibble(0x2, LOW);
    lcd_delay_millis(10);
    //confg do display
    lcd_command(0x28);
    lcd_command(0x08+0x04);
    lcd_command(0x01);
    lcd_delay_micro(15);
}



