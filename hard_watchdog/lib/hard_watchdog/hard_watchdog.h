/*
Autor:RecursiveError
Programa: Watchdog.c

Uma implementação basica do watchdog do atmel328p
--------AVISO---------
AS FUNÇÃES DESSE PROGRAMA DESATIVAM AS INTERRUPÇÕES PARA AVITAR ERROS EM SUA INICIALIZAÇÃO
*/

#ifndef hard_watchdog
#define hard_watchdog

void init_watchdog(char prescaler);
void change_prescaler(char prescaler);
void feed_watchdog(void);
#endif