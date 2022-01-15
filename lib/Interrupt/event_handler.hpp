/*
Programa: event_handler
Autor: RecursiveError

Simples Handler para as interrupções 
*/

/*
Programa: event_handler
Autor: RecursiveError

Simples Handler para as interrupções 
*/

#ifndef _EVENT_HANDLER_HPP
#define _EVENT_HANDLER_HPP

#ifndef _INT_VEC_
    #define _INT_VEC_ 26 //quantidade de interrupções
#endif
#include <stdint.h>

typedef void (*handler_func)();

namespace  interrupt{
    class Event_handler{
        public: 
            void enable();
            void desable();
            void set_handle(uint8_t interrupt_num, handler_func callback);
            friend void exec(Event_handler &event_handler, uint8_t interrupt_num);
        private:
            handler_func Handler_func[_INT_VEC_]{nullptr};
    };
}
#endif