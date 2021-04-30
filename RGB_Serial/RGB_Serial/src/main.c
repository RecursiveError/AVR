/*
Programa: RGB_Serial
Autor: RecursiveError
Programa que controla o led RBG de acordo com o caractere recebido pelo porta Serial 
*/

#include "IO.h"
#include "RGB.h"
#include "Serial.h"

unsigned char resp;

int main(){
	serial_init(9600);
	rgbInit(5, 6, 7);
	rgbColor(WHITE);
	for(;;){
		resp = serial_recive();
		switch(resp){
			case 'R':
				rgbColor(RED);
				break;
			case 'G':
				rgbColor(GREEN);
				break;
			case 'B':
				rgbColor(BLUE);
				break;
			case 'Y':
				rgbColor(YELLOW);
				break;
			case 'C':
				rgbColor(CYAN);
				break;
			case 'P':
				rgbColor(PURPLE);
				break;
			case 'W':
				rgbColor(WHITE);
				break;
			default:
				break;
		}
		serial_flush();
	}
	return 0;
}