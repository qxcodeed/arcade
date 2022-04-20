## L3 - Backtracking

Para treinar nossa técnica de backtracking, vamos fazer um exercício simples.

Seja uma linha de dados contendo uma string onde cada char da string pode ter um número entre:
- um dígito entre 0 e 9.

## Entrada e Saída
- Entrada
    - 1a linha com a string de dados
    - 2a linha com um inteiro contendo o valor de proximidade.


## Limites
- String de dados de tamanho t, 0 > t > 100
- Proximidade p, 0 > p > 100


___
Testes:

```
>>>>>>>> 02
01_2_
3
========
01320
<<<<<<<<



>>>>>>>> 02
_0__231__5
5
========
2
<<<<<<<<

>>>>>>>> 01
2__0______________3___________
3
========
1
<<<<<<<<


>>>>>>>> 03
0__32__41_
5
========
4
<<<<<<<<


>>>>>>>> 03
9____7_620_5318_____
9
========
95318746209531874620
<<<<<<<<
```
