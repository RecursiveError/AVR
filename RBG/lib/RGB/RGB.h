#ifndef RGB_H
#define RGB_H
//CORES
#define OFF    0
#define RED    1
#define GREEN  2
#define BLUE   4
#define YELLOW (RED+GREEN)
#define CYAN   (GREEN+BLUE)
#define PURPLE (RED+BLUE)
#define WHITE  (RED+GREEN+BLUE)
//define os pinos do led
void rgbInit(int pinR, int pinB, int PinG);

//muda a cor do led
void rgbColor(int color);

//liga uma cor individual do led
void turnOn(int color);

//desliga uma cor individual 
void turnOff(int color);

struct led
{
    int REDP;
    int BLUEP;
    int GREENP;
}led;


#endif