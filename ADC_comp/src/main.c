/*
Programa q lê duas portas analogicas, filtra os valores e faz uma comparação
Caso A4 e A5 sejam iguais muda a cor para vermelho
Caso A4 seja menor que A5 muda a cor para azul
Caso A4 seja maior que A5 muda a cor para verde
*/
#include "lcd.h"
#include "adc.h"
#include "RGB.h"
#include "avr/delay.h"

unsigned int adc_filter(unsigned char canal);

unsigned int A5;
unsigned int A4;

int main(){
  lcd_init();
  adc_init();
  rgbInit(5,6,7);
  lcd_send_string("ADC_5: \0");
  lcd_set_position(1,0);
  lcd_send_string("ADC_4: \0");
  for(;;){
    A5 = adc_filter(5);
    A4 = adc_filter(4);
    lcd_set_position(0,9);
    lcd_send_number(A5);
    lcd_set_position(1,9);
    lcd_send_number(A4);
    if(A4 == A5){
      rgbColor(RED);
    }
    else if(A4 < A5){
      rgbColor(BLUE);
    }
    else if(A4 > A5){
      rgbColor(GREEN);
    }
    _delay_ms(75);
  }
  return 0;
}

unsigned int adc_filter(unsigned char canal){
  unsigned long V = 0;
  unsigned int filter;
  for(int i = 0; i<5; i++){
    V += adc_read(canal); 
  }
  filter = V/5;
  return filter;
}

