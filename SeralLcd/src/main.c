
#include "console.h"
#include "Serial.h"
char c;

int main(){
  console_init();
  console_update();
  serial_init(9600);
  for(;;){
    if(serial_available()){
      while(serial_available()){
        c = serial_recive();
        switch(c){
          case '\n':
            console_move_line(1);
            console_update();
            continue;
            break;
          case 8:
            console_backspace();
            console_update();
            continue;
            break;
        }
        console_print_char(c);
      }
      console_update();
    }

  }  
  return 0;
}