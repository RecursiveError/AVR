# adc_comp

biblioteca para comparador analógico



### motivação

 essa lib é apenas um teste para mostrar o uso de abstrações no baremetal



### uso

```C++
#include "IO.hpp"
#include "adc_comp.hpp"
int comp_std{0};
int main(){
    digitalIO::DigitalIO(3).output().set_low();
    comparator::Adc_comparator().set_event(comparator::ANY, []()-> void{
		if(comparator::Adc_comparator().get_output()){
			digitalIO::DigitalIO(3).set_high();
			comp_std = 1;
		}
		else{
			digitalIO::DigitalIO(3).set_low();
			comp_std = 0;
		}
	})
	.enable();
    while(1);
    return 0;
}
```



