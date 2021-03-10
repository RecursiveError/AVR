#include "IO.h"
#include "motor.h"

void initMotor(){
    pinMode(pin1A, OUTPUT);
    pinMode(pin1B, OUTPUT);
    pinMode(pin2A, OUTPUT);
    pinMode(pin2B, OUTPUT);
}

void turnR(){
    digitalWrite(pin2A, LOW);
    digitalWrite(pin2B, LOW);
    digitalWrite(pin1A, HIGH);
    digitalWrite(pin1B, HIGH);

}

void turnL(){
    digitalWrite(pin1A, LOW);
    digitalWrite(pin1B, LOW);
    digitalWrite(pin2A, HIGH);
    digitalWrite(pin2B, HIGH);

}

void off(){
    digitalWrite(pin2A, LOW);
    digitalWrite(pin2B, LOW);
    digitalWrite(pin1A, LOW);
    digitalWrite(pin1B, LOW);

}