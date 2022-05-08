## L2 - {onlinejudge} Proximidade - achar resposta

- Seja uma sequencia inicial com uma string formada por dígitos de 0 a 9 e _
- Seja um número de proximidade P.

Objetivos:
- Você deve substituir todos os _ por dígitos seguindo as seguintes regras.
    - Só pode utilizar dígitos de 0 até P, incluindo P.
    - Qualquer dígito precisa estar a uma distância mínina de P casas de outra ocorrência dele mesmo.

- Para cada problema existe uma única solução que resolve o problema e você deve encontrá-la.

## Entrada e Saída
- Entrada
    - 1a linha com a string de dados
    - 2a linha com um inteiro contendo o valor de proximidade.
- Saída
    - A string solução do problema


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
