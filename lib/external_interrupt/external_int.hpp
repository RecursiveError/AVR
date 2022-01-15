/*
Programa: External_int
Autor: RecursiveError

lib para interrupções externas 
*/

#ifndef EXTERNAL_INT_HPP
#define EXTERNAL_INT_HPP
typedef void (*handler_func)();
namespace external_int{

    enum External_pin{
        _INT0_ = 0,
        _INT1_,
    };

    enum mode{
        LOW,
        ANY,
        DOWN,
        UP
    };
    

    class External_int{
        public:
            //Desabilita a interrupção (NÃO DESABILITA A CHAVE DE INTERRUPÇÃO GLOBAL!)
            External_int& disable(int pin);
            //cria um handler para o evento
            External_int& event_on(int pin, int mode, handler_func callback = nullptr);
    };
}
#endif