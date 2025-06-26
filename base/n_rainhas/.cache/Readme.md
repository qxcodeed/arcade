# N-Rainhas

![_](https://raw.githubusercontent.com/qxcodeed/arcade/master/base/n_rainhas/cover.jpg)

O problema das **N-Rainhas** consiste em posicionar `N` rainhas em um tabuleiro de xadrez `N x N` de forma que **nenhuma rainha ataque outra**. Ou seja:

- Nenhuma rainha pode estar na **mesma linha**
- Nenhuma rainha pode estar na **mesma coluna**
- Nenhuma rainha pode estar na **mesma diagonal**


Dado um número inteiro `n`, encontrar **todas as soluções possíveis** para posicionar `n` rainhas em um tabuleiro `n x n` de modo que nenhuma possa atacar a outra.

---

## Entrada

A entrada consiste em um único número inteiro:

- `n` — número de rainhas e dimensão do tabuleiro  
  $1 \leq n \leq 15$

## Saída

- Quantidades de maneiras possíveis para posicionar `n` rainhas em um tabuleiro `n x n`

### Exemplo

```txt
>>>>>>>>>>>
4
<<<<<<<<<<<
2
```
### Explicação
Em um tabuleiro 4 x 4 com 4 rainhas temos 2 maneiras possíveis para posicionar 4 rainhas de modo que nenhuma ataque a outra.
