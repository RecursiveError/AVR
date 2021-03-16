#ifndef _DISP_H
#define _DISP_H


//liga o display
void dispInit();

//atualiza as informaçoes 
void dispUpdate();

//escreve o valor num dos segmentos do display
int dispWrite(int posi, int value);

//envia as informações para o display
int send(int value);


#endif