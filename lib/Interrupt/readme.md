# Interrupt

essa biblioteca abstrai os handlers de interrupções do Atmel328p



### motivação 

o uso de interrupções é muito importante para trabalhar com qualquer sistema embarcado, seu uso em C apesar de simples tem muitas limitações devido a própria linguagem.



Em C++ você tem acesso a muitas abstrações e uma delas é muito útil para se trabalhar com interrupções, as expressões lambdas, elas facilitam muito a passagem de funções para a interrupção por meio de callbacks 

(pelo fato da AVR-libc não suportar a STL, não é possível utilizar a biblioteca functional, por tanto esse codigo não suporta closures)

### uso 

```C++
#include "interrupt.hpp"
#include "IO.hpp"

int main(){
	interrupt::handler.set_handle(INT0_vect_num,[]() -> void{
		digitalIO::DigitalIO(6).toggle();
	});
	return 0;
}
```



​     

