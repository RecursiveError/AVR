# USART

biblioteca para uso da comunicação serial do Atmel328p



### motivação 

Abstrair essa funcionalidade permite que o programador configure rapidamente sem se preocupar com os registradores



### USO

```c++
#include "usart.hpp"
#include "util/delay.h"

const int rate = 9600;
const char msg[] = "ola mundo\n\0";
int main(){
    usart::Usart output;
    output.enable(rate);
    while(true){
        for(auto i : msg){
            output.transmit(i);
        	}
        _delay_ms(500);
		}
    return 0;
}
```

