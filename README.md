# AVR
**Projetos de baixo nivel com Atmel328p**

Esse repositorio tem o intuito de documentar meu aprendizado com sistemas embarcados,
cada subdiretório contém uma biblioteca mais uma prova de conceito de uma funcionalidade básica de um sistema embarcado. 
**V 7.2.1**

Atualmente o projeto conta com
- [x] IO de portas digitais
- [x] Comunicação Serial
- [x] Portas ADC
- [x] Portas PWM
- [x] Timers
- [x] Interrupções
- [X] Watchdogs 
- [X] EEPROM
- [ ] Fuse
- [ ] Kernel
- [ ] BRTOS
- [ ] Assembly


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
> - RGB_Serial: https://youtu.be/vqYLxVNObTk
> - SerialLcd: https://youtu.be/RTHadXwnF90

### Portas ADC
> - ADC: https://youtu.be/fZpCz_bOyFc
> - ADC_comp: https://youtu.be/QP2Ig5rxqEo

### Portas PWM
> - PWM: https://youtu.be/opz_oydRdKY

### TIMERS/Interrupções
> - timers: https://youtu.be/hvz0_dEjCEA 
> - lcd_clock: https://youtu.be/c_ZehN7GX-A

### WATCHDOGS
> - soft_watchdog: SEM VIDEO DISPONIVEL (o exemplo apenas pisca um led)
> - hard_watchdog: SEM VIDEO DISPONIVEL (o exemplo apenas pisca um led)

### EEPROM
> - EEPROM: https://youtu.be/7k3nuO6U4ps

## Notas adicionais
Como esse repositório é apenas para documentar meu aprendizado, resolvi criar essas notas para explicar o que e porque fiz 
para mim mesmo e para outros que possam estar lendo isso

- agora marcarei a versão para facilitar a leitura desse documento
- **[Topico atual].[projetos do topico].[mudaças ocasionais neste documento]**
- <s>cada topico conta com um projeto final, que será criado apos o termino dele</s>
- os projetos finais vão envolver varios topicos caso sejam curtos
- Os projetos finais vão ter repositórios próprios 
- Comunicação Serial só terá os protocolos existentes no hardware do Atmel328p (USART, SPI, I2C)
- USART será o foco dos exemplos, os outros protocolos teram apenas suas provas de conceito
