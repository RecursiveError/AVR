# ADC 

biblioteca para uso das portas adc do Atmel328p



### motivação 

Abstrair os registradores para uma facilitar seu uso



### USO 

```C++
#include "adc.hpp"

int main(){
    uint16_t result;
    adc::Adc scanner(adc::AVCC, 7, false);
    result = scanner.read(adc::ADC0);
    return 0;
}
```



