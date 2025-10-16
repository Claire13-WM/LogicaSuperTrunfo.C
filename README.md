# 🌍 Super Trunfo: Países

Jogo *Super Trunfo* desenvolvido em *C, com o tema **países*.  
Compare cartas com base em atributos e descubra qual país vence!

---

## 🎴 Cartas disponíveis

| País            | População (milhões) | Área (km²) | PIB (bilhões US$) | IDH  |
|-----------------|------------------|------------|-----------------|------|
| 🇧🇷 Brasil       | 214              | 8516       | 2290            | 0.765|
| 🇺🇸 Estados Unidos | 331              | 9834       | 25700           | 0.921|
| 🇯🇵 Japão        | 125              | 377        | 4960            | 0.925|
| 🇫🇷 França       | 67               | 551        | 3410            | 0.903|

---

## ⚡ Como jogar

1. Compile e execute o programa logica.supertrunfo.c.  
2. Escolha uma opção no menu:  

   - *1 - Ver cartas*: mostra todas as cartas e seus atributos.  
   - *2 - Comparar um atributo*: escolha duas cartas e o atributo para comparar.  
   - *3 - Comparar dois atributos*: escolha duas cartas e dois atributos para comparar.  
   - *4 - Sair*: encerra o jogo.  

3. O programa indica quem vence ou se houve empate com base nos atributos escolhidos.

---

## 🛠 Como compilar

No terminal, dentro da pasta do projeto:  

```bash
gcc logica.supertrunfo.c -o supertrunfo
./supertrunfo
