# L1 - Gerenciando @chaves de disputas usando uma fila

- Veja a versão online: [aqui.](https://github.com/qxcodeed/arcade/blob/master/base/chaves/Readme.md)
- Para programar na sua máquina (local/virtual) use:
  - `tko down ed chaves`
- Se não tem o `tko`, instale pelo [LINK](https://github.com/senapk/tko#tko).

---

Este ano tem Copa do Mundo! O país inteiro se prepara para torcer para a equipe canarinho conquistar mais um título, tornando-se hexacampeã.

Na Copa do Mundo, depois de uma fase de grupos, dezesseis equipes disputam a Fase Final, composta de quinze jogos eliminatórios. A figura abaixo mostra a tabela de jogos da Fase Final:

![_](https://raw.githubusercontent.com/qxcodeed/arcade/master/base/chaves/cover.jpg)

Dados os resultados dos quinze jogos da Fase Final, escreva um programa que determine a equipe campeã.

## Entrada

A entrada é composta de quinze linhas, cada uma contendo o resultado de um jogo. A primeira linha contém o resultado do jogo de número 1, a segunda linha o resultado do jogo de número 2, e assim por diante. O resultado de um jogo é representado por dois números inteiros MM e NN separados por um espaço em branco, indicando respectivamente o número de gols da equipe representada à esquerda e à direita na tabela de jogos.

## Saída

Seu programa deve imprimir uma única linha, contendo a letra identificadora da equipe campeã.

## Entradas de amostra

```txt
>>>>>>>> 01
4 1 
1 0 
0 4 
3 1 
2 3 
1 2 
2 0 
0 2 
1 2 
4 3 
0 1 
3 2 
3 4 
1 4 
1 0
========
F
<<<<<<<<

>>>>>>>> 02
2 0 
1 0 
2 1 
1 0 
1 0 
1 2 
1 2 
1 0 
2 1 
1 0 
0 1 
0 2 
2 1 
1 0 
2 1
========
A
<<<<<<<<
```

## Dica

- Coloque as 16 letras em uma fila
- Pegue as duas primeiras
  - que no caso seriam A e B
  - leia os gols
  - decida quem você coloca de novo na fila
- Continue até que só existe um elemento na fila
