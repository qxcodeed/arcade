## L2 - {onlinejudge} Distância: resolução

![](__capa.jpg)

- Seja uma sequencia inicial uma string formada por dígitos e underlines `_`.
- Seja um valor de distância D.

Objetivos:
- Você deve substituir todos os _ por dígitos seguindo as seguintes regras.
    - Só pode utilizar dígitos de 0 até D, incluindo D.
    - Qualquer dígito precisa estar a uma distância mínima de D casas de outra ocorrência dele mesmo, tanto à esquerda como à direita.

- Para cada problema, existe uma e somente uma solução.

## Entrada e Saída
- Entrada
    - 1a linha: sequência.
    - 2a linha: valor de D.
- Saída
    - A string solução do problema


## Limites
- sequência de tamanho t, 0 > t > 100
- 0 > D > 100

___
Testes:

```


>>>>>>>>
01_2_
3
========
01320
<<<<<<<<



>>>>>>>> 02
_0__231__5
5
========
1045231045
<<<<<<<<

>>>>>>>> 01
2__0______________3___________
3
========
213021302130213021302130213021
<<<<<<<<


>>>>>>>> 03
0__32__41_
5
========
0413250413
<<<<<<<<


>>>>>>>> 03
9____7_620_5318_____
9
========
95318746209531874620
<<<<<<<<
```
