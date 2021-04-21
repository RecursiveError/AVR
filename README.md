# AVR
**Projetos de baixo nivel com Atmel328p**

Esse repositorio tem o intuito de documentar meu aprendizado com sistemas embarcados,
cada subdiretório contém uma biblioteca mais uma prova de conceito de uma funcionalidade básica de um sistema embarcado 

Atualmente o projeto conta com
- [x] IO de portas digitais
 
- [x] Comunicação Serial
- [ ] Portas ADC
- [ ] Portas PMW
- [ ] Timers
- [ ] Interrupções 
- [ ] Watchdogs
- [ ] Kernel


## Vídeos dos projetos
### Digital IO
> - IO:  https://www.youtube.com/watch?v=IS5MIF0gM9Y
> - RGB: https://www.youtube.com/watch?v=fydgfV9knUA
> - Motor: https://www.youtube.com/watch?v=56Pg4UlAeZs
> - Disp: https://www.youtube.com/watch?v=LtMCkzgFJTE
> - LCD: https://www.youtube.com/watch?v=zkkNk1EBBPY
> - keypad: https://www.youtube.com/watch?v=1YmLfUYxb0M
> - Console: https://www.youtube.com/watch?v=JzjXAL53uFY
#### Projeto final de IO: https://github.com/RecursiveError/595LCD

### Comunicação Serial
> - Serial: https://www.youtube.com/watch?v=xhvO6p-LsEw

## Notas adicionais
Como esse repositório é apenas para documentar meu aprendizado, resolvi criar essas notas para explicar o que e porque fiz 
para mim mesmo e para outros que possam estar lendo isso

- cada topico conta com um projeto final, que será criado apos o termino dele
- "Console" marca o fim do topico IO
- Os projetos finais vão ter repositórios próprios 
- Nenhuma lib do tópico de Comunicação Serial sera via software, pois isso envolve temas como Interrupções e Timers
- Comunicação Serial só terá os protocolos existentes no hardware do Atmel328p (I2C, USART, SPI)
- USART será o foco dos exemplos, os outros protocolos teram apenas suas provas de conceito
