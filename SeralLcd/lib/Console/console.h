#ifndef _CONSOLE_H
#define _CONSOLE_H


void console_init();
void console_print(char* vet);
void console_print_char(char data);
void console_update();
void console_backspace();
void console_move_line(int move);

#endif