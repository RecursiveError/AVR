/**
 * Autor:RecursiveError
 * Ex do uso da karnel
 * **/

#include <RecursiveError/avr_framework.hpp>

#define LED 5
#define FAIL_LED 3
#define OK_LED 4
#define LCD_LINE 2
#define LCD_COLS 16
#define LCD_BUFFER (LCD_LINE * LCD_COLS) + 1
#define KERNEL_BUFFER 9
#define UBRR 9600

core::Kernel<KERNEL_BUFFER> main_proc;
usart::Usart Interface;
liquidcrystal::Liquidcrystal output(liquidcrystal::Lcd_4bits(7,6,8,9,10,11));
char lcd_buffer[LCD_BUFFER];


//inicia o display
status_t display_init(){
	output.init(LCD_COLS,LCD_LINE)
		.write("OK!")
		.set_cursor(0,0);
	return SUCCESS;

}

//inicia os GPIOs
status_t IO_init(){
	digitalIO::DigitalIO(LED).output().set_low();
	digitalIO::DigitalIO(FAIL_LED).output().set_low();
	digitalIO::DigitalIO(OK_LED).output().set_low();
	return SUCCESS;
}

//inicia a comunicação serial
status_t usart_init(){
	Interface.enable(UBRR).flush();
	return SUCCESS;
}

//inicializa o buffer
status_t buffer_init(){
	for(int i; i<LCD_BUFFER; i++){
		lcd_buffer[i] = '\0';
	}
	return SUCCESS;
}

//escreve as informação recebias na serial
status_t print_usart(){
	output.config(0x01).set_cursor(0,0);
	size_t i = 0;
	while(lcd_buffer[i] != '\0'){
		output.write(lcd_buffer[i++]);
		if(i == 16){
			output.set_cursor(1,0);
		}
	}
	return SUCCESS;
}

//apenas pisca um led
status_t blink(){
	digitalIO::DigitalIO(LED).toggle();
	return REPEAT;
}

//verifica chegou infomações pela serial e escreve bo buffer
status_t check_usart(){
	static size_t i = 0;
	if(Interface.available()){
		char data = 0;
		data = Interface.recive();
		if(data == 0x08){
			if(i != 0){
				lcd_buffer[--i] = '\0';
			}
		}else{
			if(i < 32)lcd_buffer[i++] = data;
		}
		main_proc.addFunc(print_usart);
	}
	return REPEAT;
}

int main(){
	main_proc.addFunc(buffer_init);
	main_proc.addFunc(display_init);
	main_proc.addFunc(IO_init);
	main_proc.addFunc(usart_init);
	main_proc.addFunc(blink);
	main_proc.addFunc(check_usart);
	for(;;){
		if(main_proc.loop() != FAIL){
			digitalIO::DigitalIO(FAIL_LED).set_low();
			digitalIO::DigitalIO(OK_LED).set_high();
		}else{
			digitalIO::DigitalIO(FAIL_LED).set_high();
			digitalIO::DigitalIO(OK_LED).set_low();	
		}
	}
	return SUCCESS;
}