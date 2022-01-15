#  Liquidcrystal

biblioteca para trabalhar com displays LCD

(por enquanto somente os LCD compatíveis com o controlador HD44780, por falta de hardware para teste)



### motivação 

o uso desse tipo de dispositivo é bastante complexo em C, pela falta de OO e fica muito difícil manter um código com vários tipos de LCD 



outra motivação é a quebra das boas práticas de OO e o pobre uso dos recursos da linguagem em outras bibliotecas para embarcados, é totalmente possível ter um codigo embarcado e moderno sem abrir mão do desempenho, esta biblioteca apesar de simples segue todos os conceitos de S.O.L.I.D e possue uma escrita fluida 



### uso 

```C++
#include "liquidcrystal.hpp"

using namespace liquidcrystal;

int main(){
    
	Liquidcrystal(Lcd595(4,13,12,2,3))
		.init(16,2)
		.write("ola, mundo!")
		.set_cursor(1,10)
		.write("TESTE");

	Liquidcrystal(Lcd2EN_4bits(7,6,5,8,9,10,11))
		.init(40, 4)
		.write("ola, mundo!")
		.set_cursor(1,0)
		.write("bom dia")
		.set_cursor(2,10)
		.write("123456789");

	for(;;);
	return 0;
}
```


### Alterações 
 - smart pointers removidos
 > motivo:
 >
 > por ser uma plataforma limitada o uso de alocação dinamica pode gerar problemas como fragmentação de memoria, a linguagem não tem relações com o problema



