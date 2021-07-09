/*
Autor:RecursiveError
Programa:soft_wtd-
-------------------------------------------------------------
Um simples watchdog por software q ativa a cada ~1ms

-------AVISO--------
esse programa utiliza o TC0 e habilita a chave global de interrupção 
*/

#ifndef soft_wtd
#define soft_wtd

void watchdog_init(void);
void watchdog_feed(void);
void watchdog_disable(void);
unsigned char get_flag(void);

#endif