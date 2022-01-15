# IO

essa biblioteca abstrai os portas digitais do arduino uno em classes facilitando o uso



### motivação

essa estrutura foi escolhida por tratar as portas digitais como classes, tornando facil sua utilização



### uso

 ```c++
 #include <IO.hpp>
 #include <util/delay.h>
 #define porta 5
 digitalIO::DigitalIO led(porta);
 int main(){
     led.output().set_low();
     for(;;){
         led.toggle();
         _delay_ms(1000);
 	}
     return 0;
 }
 ```



 

