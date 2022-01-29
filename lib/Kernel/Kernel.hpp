/**
 * Autor:RecursiveError
 * Programa: Kernel
 * Versão: 0.1
 * 
Primeira versão de kernel basico para MCUs
 **/

#ifndef KERNEL_HPP
#define KERNEL_HPP
#include <status.hpp>
#include <Buffer.hpp>

namespace core {
    using Kernel_callback = status_t(*)(void);
    template<const int buffer_size>
    class Kernel{
        public:
            status_t init(){
                Kernel_buffer.clear();
                return SUCCESS;
            }
            
            status_t addFunc(Kernel_callback func){
                return Kernel_buffer.add(func);
            }

            status_t loop(){
                Kernel_callback proc = Kernel_buffer.read();
                if(proc != nullptr){
                    status_t status = proc();
                    if(status == REPEAT){
                        Kernel_buffer.add(proc);
                    }
                return status;
                }else{
                    return FAIL;
                }
                return FAIL;
            }
        private:
            buffer::Circular<Kernel_callback,buffer_size> Kernel_buffer;
    };
}
#endif