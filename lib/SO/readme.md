# so

essa biblioteca abstrai expansores de portas 

(por agora somente o 74hc595, por falta de componestes para teste)



### motivação 

o uso desse tipo de componente é bastante complicado em C, pelo fato da linguagem não possuir orientação a objetos o programador faria o seguinte código:

```c
struct Expander {
    uint8_t data_pin;
    uint8_t clock_pin;
    uint8_t enable_pin;
};

Expander_init(Struct Expander *SO);
Expander_send(Struct Expander *SO, uint8_t value);


int main(){
    int data_pin = 4;
    int clock_pin = 13;
    int enable_pin = 12;
    uint8_t valor = 0b01000100;
    struct Expander my_expander{data_pin, clock_pin, enable_pin};
    Expander_init(&my_expander);
    Expander_write(&my_expander, valor);
    for(;;);
	return 0;
}
```



o código é trivial para qualquer programador C, porém a medida que o projeto cresce seu uso fica cada vez mais complicado por não possuir polimorfismo, encasulamento e namespaces, além do mais o programador ainda precisa  passar a variável correta a cada chamada o que torna o trabalho mais cansativo



por esses motivos essa biblioteca em C++ foi criada



### uso

```C++
#include "expander_74hc595.hpp"

int main(){
    int data_pin = 4;
    int clock_pin = 13;
    int enable_pin = 12;
    uint8_t valor = 0b01000100;
	serial_output::Expander_74hc595 Expander(data_pin,clock_pin,enable_pin);
	Expander.init().send(valor);
    for(;;);
	return 0;
}
```



 

