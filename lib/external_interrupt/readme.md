# External_int

biblioteca para trabalhar com as interrupções externas no Atmel328p



### motivação 

Essa biblioteca abstrai o uso da interrupções externas.

é apenas um teste para mostrar o uso de abstrações no baremetal



### uso

```C++
#include "external_int.hpp"
#include "util/delay.h"
#include "IO.hpp"

using namespace external_int;
int main(){

	External_int()
		.event_on(_INT0_, _DOWN_, [](){
			digitalIO::DigitalIO(4).output().toggle();
		})
		.event_on(_INT1_, _ANY_, [](){
			digitalIO::DigitalIO(6).toggle();
		});

	for(;;){
		digitalIO::DigitalIO(3).output().toggle();
		_delay_ms(500);
	}
	return 0;
}
```

