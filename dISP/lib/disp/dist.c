/*
Autor: RecursiveError

porque criar uma manipulação bit a bit do zero e não usar a IO? porque é mais facil e eficiente
basta olhar a função send
*/
#include "disp.h"
#include "Register/Register.h"


//valores constantes para simbolos disponiveis no display
static const  unsigned char conv[] = {0XD7, 0X11, 0XCD, 0X5D, 0X1B, 0X5E, 0XDE, 0X15,
0XDF, 0X5F, 0X9F, 0XDA, 0XC6, 0XD9, 0XCE, 0X8E, 0xC2};

static int n1, n2, n3, n4;
static int disp;

void dispInit(){
    DDRD = 0XFF;
    DDRB = 0XFF;
}

int send(int value){
    PORTD =  0X00;
    PORTD |= value;

    return value;
}

int dispWrite(int posi, int value){
    if(posi == 1) n1 = value;
    if(posi == 2) n2 = value;
    if(posi == 3) n3 = value;
    if(posi == 4) n4 = value;
    if(posi >  4) return -1;
}

void dispUpdate(){
    PORTB = 0x00;
    switch (disp)
    {
    case 0: send(conv[n1]); 
        PORTB |= 1<<0; 
        disp = 1;
        break;
    case 1:
        send(conv[n2]);
        PORTB |= 1<<1;
        disp = 2;
        break;
    case 2:
        send(conv[n3]);
        PORTB |= 1<<2;
        disp = 3;
        break;
    case 3:
        send(conv[n4]);
        PORTB |= 1<<3;
        disp = 0;
        break;
    default:
        disp = 0;
        break;
    }
}