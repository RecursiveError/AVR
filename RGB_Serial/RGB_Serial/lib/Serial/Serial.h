#ifndef _SERIAL_H
#define _SERIAL_H
void serial_init(unsigned int rate);
void serial_send(unsigned int data);
unsigned char serial_recive();
void serial_flush();
#endif