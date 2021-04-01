/*
Autor: RecursiveError
Teste para a lib de console feita por mim 
*/

#include "console.h"
#include "IO.h"
#include "keypad.h"

unsigned int valor;
unsigned int valorAnterior;

int main(){
	console_init();
  	keypad_init();
  	console_print("Linha 0\n");
  	console_print("Linha 1\n");
  	console_print("Linha 2\n");
  	console_print("Linha 3\n");
  	console_update();
  	for(;;){
    	keypad_debounce();
    	valor = keypad_read();
    	//executa apenas se o estado do botão mudar
    	if(valor != valorAnterior){
      	if(bitTst(valor, 0)){
        	console_move_line(1);
        	console_update();
      	}
      	if(bitTst(valor, 1)){
        	console_move_line(-1);
        	console_update();
      	}
      	valorAnterior = valor;
    	}
  	}
  	return 0;
}