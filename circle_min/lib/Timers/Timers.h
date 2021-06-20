/*
Programa: Timers.h
Autor:RecursiveError
DATA: 19/06/2021
Objetivo: Programa para gerenciar um tempo minimo para um ciclo do loop principal
podendo ir de ~1ms até ~1s

*/

#ifndef R_TIMERS
#define R_TIMERS
void timer_init(void);
int timer_start(unsigned int value);
int timer_read(void);
int timer_finished(void);
void timer_delay(unsigned int delay);
void timer_wait(void);

#endif