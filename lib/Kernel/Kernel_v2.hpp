/**
 * Autor:RecursiveError
 * Programa: Kernel
 * Versão: 0.2
 * 
Primeira versão de kernel basico para MCUs
 **/

#ifndef KERNELV2_HPP
#define KERNELV2_HPP
#include <status.hpp>

#include <process.hpp>

namespace core {
    using namespace process;
    template<const int buffer_size>
    class Kernel{
        public:
            status_t init(){
                start = 0;
                end = 0;
                return SUCCESS;
            }
            
            status_t create_task(Process* task){
                if ((end+1)%buffer_size != start){
                    task->deadline += task->period;
                    Kernel_buffer[end] = task;
                    end = (end+1)%buffer_size;
                    return SUCCESS;
                }
                return FAIL;
            }

            status_t loop(){
                uint32_t count;
                uint32_t next;
                Process* temp;
                for(;;){
                    if(start != end){
                        count = (start+1)%buffer_size;
                        next = start;
                        while(count != end){
                            if((Kernel_buffer[count]->deadline < Kernel_buffer[next]->deadline)){
                                next = count;
                            }
                            count = (count+1)%buffer_size;
                        }
                        temp = Kernel_buffer[next];
                        Kernel_buffer[next] = Kernel_buffer[start];
                        Kernel_buffer[start] = temp;
                        while((Kernel_buffer[start]->deadline) > 0){
                            //NOP
                        }
                        switch(Kernel_buffer[start]->Fun_ptr()){
                            case FAIL:
                                break;
                            case SUCCESS:
                                break;
                            case REPEAT:
                                create_task(Kernel_buffer[start]);
                                break;
                        }
                        start = (start + 1) % buffer_size;
                    }
                }
            }

            void kernel_tick(){
                uint32_t proc = start;
                while(proc != end){
                    if(Kernel_buffer[proc]->deadline > 0){
                        Kernel_buffer[proc]->deadline--;
                    }
                    proc = (proc+1)%buffer_size;
                }
            }

        private:
            uint32_t start{0};
            uint32_t end{0};
            volatile Process* Kernel_buffer[buffer_size];
    };
}
#endif