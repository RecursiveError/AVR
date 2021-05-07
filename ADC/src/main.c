#include "lcd.h"
#include "adc.h"
#include "avr/delay.h"

int main(){
  lcd_init();
  adc_init();
  lcd_send_string("---Portas ADC---\0");
  for(;;){
    lcd_set_position(1,0);
    lcd_send_number(adc_read(5));
    _delay_ms(50);
  }
  return 0;
}

