/*
Autor:RecursiveError
Programa:Buffer
Um buffer circular para uso no Kernel
*/
#ifndef BUFFER_HPP
#define BUFFER_HPP
#include <status.hpp>
namespace buffer{
    template<typename T, const int SIZE>
    class Circular {
        public:
         status_t add(T new_info){
             if((end+1)%SIZE != start){
                 buffer[end] = new_info;
                 end = (end+1)%SIZE;
                 return SUCCESS;
             }
             return FAIL;
         }

         T read(){
             if(start != end){
                 int temp = start;
                 start = (start+1)%SIZE;
                 return buffer[temp];
             }
             return nullptr;
         }

         status_t clear(){
            for(auto i: buffer){
                i = nullptr;
            }
            start = 0;
            end = 0;
            return SUCCESS;
         }
        
        private:
         T buffer[SIZE]{nullptr};
         int start{0};
         int end{0};
    };
}

#endif