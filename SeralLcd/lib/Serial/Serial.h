#ifndef _SERIAL_H
#define _SERIAL_H
void serial_init(unsigned int rate);
void serial_send(unsigned int data);
unsigned char serial_recive();
unsigned char serial_available();
void serial_flush();
#endif