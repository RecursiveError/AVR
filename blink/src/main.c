//com defines 
#define DDRD  (*(volatile unsigned char*) (0x0A + 0X20))
#define PORTD (*(volatile unsigned char*) (0x0B + 0X20))
#define setbit(var, bit) (var |= (1<<bit))
#define flpbit(var, bit)  (var ^= (1<<bit))


void main(void){
    volatile unsigned long int millis = 0;
    /*
    //Com variaves simples 
    volatile unsigned char *PORTD = 0X0B + 0X20;
    volatile unsigned char *DDRD = 0x0A + 0X20;
    */

    setbit(DDRD, 4);
    setbit(PORTD, 4);
    for(;;){
        if(!(millis % 10000)){
            flpbit(PORTD, 4);
        }

        millis++;
    }
}