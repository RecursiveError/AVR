/*
Programa: event_handler
Autor: RecursiveError

Simples Handler para as interrupções 
*/

#include "event_handler.hpp"
namespace interrupt{
    void Event_handler::enable(){
        __asm__ __volatile__ ("sei" ::: "memory");
    }

    void Event_handler::desable(){
        __asm__ __volatile__ ("cli" ::: "memory");
    }

    void Event_handler::set_handle(uint8_t interrupt_num, handler_func callback){
        if(callback == nullptr || interrupt_num > _INT_VEC_) return;
        this->Handler_func[interrupt_num] = callback;
    }

    void exec(Event_handler &event_handler,uint8_t interrupt_num){
        if(event_handler.Handler_func[interrupt_num] != nullptr){
            event_handler.Handler_func[interrupt_num]();
        }
    }
}