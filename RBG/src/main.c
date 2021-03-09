/*Autor: RecursiveError
programa que alterna entre 7 cores do led RGB
*/

#include "IO.h"
#include "RGB.h"

unsigned long int millis;
short int cor;

int main(){
  rgbInit(7, 8, 9);
  rgbColor(WHITE);
  for(;;){
    if(!(millis % 10000)){
      rgbColor(cor);
      cor++;
      if(cor > 7) cor = 1;
    }
    millis++;
  }
}