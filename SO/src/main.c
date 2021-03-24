//mesmo exemplo do LCD

#include "lcd.h"
#include "IO.h"
#include "SO.h"
int main(){
  //simbolo de raio
  char raio[8] = {0X03, 0X06, 0X0C, 0X1F, 0X1F, 0X03, 0X06, 0X0C};
  so_init();

  lcd_init();
  //guarda o simbolo na memoria 0 do display
  lcd_command(0X40);
  for(int i =0; i<8; i++){
    lcd_send_char(raio[i]);
  }
  lcd_set_position(0,0);
  lcd_send_char(0);
  lcd_set_position(0,4);
  lcd_send_string("OLA MUNDO");
  lcd_set_position(0,15);
  lcd_send_char(0);

  lcd_set_position(1,0);
  lcd_send_char(0);
  lcd_send_string("RecursiveError");
  lcd_send_char(0);
  for(;;);
  return 0;
}