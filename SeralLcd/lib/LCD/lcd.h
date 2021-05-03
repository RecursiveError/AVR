#ifndef _LCD_H
#define _LCD_H

#define RS 6
#define EN 7
void lcd_init();
void lcd_send_char(char value);
void lcd_send_string(char string[]);
void lcd_send_number(int value);
void lcd_set_position(int linha, int coluna);
void lcd_pulse();
void lcd_command(char value);



#endif