## L3 - {onlinejudge} Proximidade - menor P

Para treinar nossa técnica de backtracking, vamos fazer um exercício simples.

Seja uma linha de dados contendo uma string onde cada char da string pode ter duas possibilidades:
- um dígito entre 0 e 9.
- um .

Nosso problema tem 2 parâmetros: a linha com os valores e o valor de `proximidade`.

- Nosso objetivo é substituir os '.' por valores entre [0 e N], desde que nunca existam dois números iguais `próximos`.
- E achar o menor valor de N que resolve o problema.

Se nosso valor de proximidade for 1, basta que os elementos ao lado não sejam iguais. Se a proximidade for 2, os elementos até duas casas de distância não podem ser iguais. 

- Seja a string "..0", com proximidade 1.
    - Para N igual a 1 a resposta será "010".

- Seja a string "1.0", com proximidade 1.
    - Para N igual a 1 não é não é possível resolver esse problema.
    - Para N igual a 2, a resposta será "120".

- Seja a string "..0..", com proximidade 2. 
    - Isso significa que nenhum dos valores a ser preenchidos, pode ter valor 0. 
    - Para N igual a 2 temos várias possibilidades de solução:
        - "12012" ou "21021".

- Seja a string "0...1.30..2" e proximidade 3. 
    - N == 4 é o menor N e "02341230142" uma possível solução.

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
>>>>>>>> 01
.........1
1
========
1
<<<<<<<<

>>>>>>>> 02
......1
2
========
2
<<<<<<<<

>>>>>>>> 03
...1....2..0
3
========
4
<<<<<<<<


>>>>>>>>
.201.34.23.0
3
========
5
<<<<<<<<

>>>>>>>> 03
.201.34.23.0....1..2...3......1.2....3..4..5....56..3.1
7
========
9
<<<<<<<<
```
