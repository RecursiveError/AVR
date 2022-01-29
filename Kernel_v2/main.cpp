/**
 * Autor:RecursiveError
 * Ex do uso da karnelv2
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
liquidcrystal::Liquidcrystal output(liquidcrystal::Lcd_4bits(7,6,8,9,10,11));


//inicia o display
status_t display_init(){
	output.init(LCD_COLS,LCD_LINE)
		.write("OK")
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

//apenas pisca um led
status_t blink(){
	digitalIO::DigitalIO(LED).toggle();
	return REPEAT;
}

status_t write_tick(){
	output.config(0)
		.set_cursor(0,0)
		.write("tick:");
	return SUCCESS;
}

status_t tick_counter(){
	static int tick;
	output.set_cursor(0, 8)
		.write(tick);
	tick++;
	return REPEAT;
}

int main(){

	//configura o tempo (1 == 1ms);
	TCCR0A = 0;
	TCCR0B = 0;
	TIMSK0 = (1<<TOIE0);
	
	//handler do timer
	interrupt::handler.set_handle(TIMER0_OVF_vect_num, [](){
		main_proc.kernel_tick();
	});

	//inicia o timer
	interrupt::handler.enable();

	//pool de processos
	process::Process IO = {IO_init, 0, 0};
	process::Process stdout_init = {display_init, 0, 0};
	process::Process write = {write_tick, 0, 0};
	process::Process update = {tick_counter, 100, 0};
	process::Process led_blick = {blink, 1000, 0};


	//inicia a kernel
	main_proc.init();
	main_proc.create_task(&IO);
	main_proc.create_task(&stdout_init);
	main_proc.create_task(&write);
	main_proc.create_task(&update);
	main_proc.create_task(&led_blick);

	//loop principal
	TCCR0B = (1<<CS01) | (1<<CS00);
	main_proc.loop();
	return SUCCESS;
}