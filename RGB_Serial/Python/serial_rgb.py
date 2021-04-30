#!/usr/bin/python

'''
Programa: serial_rgb
Autor: RecursiveError
Script para enviar caracteres pela porta serial
'''


import serial
import os

#cores
w = '\033[30m'
r = '\033[31m'
g = '\033[32m' 
y = '\033[33m'
b = '\033[34m'
p = '\033[35m'
c = '\033[36m'
clear = '\033[0m'

def show_colors():
    print(f'''
__Cores__
{r}|RED{clear}   |
{g}|GREEN{clear} |
{b}|BLUE{clear}  |
{y}|YELLOW{clear}|
{c}|CYAN{clear}  |
{p}|PURPLE{clear}|
{clear}|WHITE{clear} |
-------- 
''')

def main():
    porta = serial.Serial()
    porta.port = '/dev/ttyUSB0'
    porta.baudrate = 9600
    porta.open()
    while(1):

        show_colors()
        resp = input("Digite a cor(quit para sair): ")
        os.system("clear")
        if resp.strip() in 'quit':
            porta.close()
            print("vlw flw")
            exit(0)

        if resp.strip()[0].upper() not in 'RGBYCPW':
            print("COR INVALIDA")
            continue

        porta.write(bytes(resp.strip()[0].upper(), 'ascii'))
    return 0

if __name__ == '__main__':
    main()