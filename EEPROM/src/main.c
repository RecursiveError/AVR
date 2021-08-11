
#include <avr/io.h>
#include <avr/eeprom.h>
#include <avr/delay.h>
#include "IO.h"
#include "lcd.h"
#include "SO.h"

unsigned int tick = 0;
unsigned int EEMEM tick_eeprom = 0;

int main(){
	char prev_std;
	so_init();
	lcd_init();
	pinMode(7,INPUT);
	tick = eeprom_read_word(&tick_eeprom);
	lcd_set_position(0,0);
	lcd_send_number(tick);
	for(;;){
		while(digitalRead(7)){
			prev_std = 1;
			tick++;
			lcd_set_position(0,0);
			lcd_send_number(tick);
		}
		if(!digitalRead(7) && prev_std){
			prev_std = 0;
			if(tick == 0xFFFF) tick = 0;
			eeprom_write_word(&tick_eeprom, tick);
			_delay_ms(100);
		}
	}
	return 0;
}