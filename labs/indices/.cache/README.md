# Índices originais

<!-- toch -->
[Intro](#intro) | [Exemplos](#exemplos)
-- | --
<!-- toch -->

## Intro

Você recebe um vetor A de inteiros não negativos de tamanho n. Sua tarefa é ordenar o vetor em ordem crescente e imprimir os índices originais dos elementos.

Considere o vetor `A = {4,5,3,7,1}`

Após a ordenação, o vetor ordenado será: `A = {1,3,4,5,7}`.

A saída deve ser os índices originais dos elementos do vetor ordenado: `4 2 0 1 3`

**NOTA:** A indexação da vetor começa com 0.

### Entrada

- A primeira linha de entrada consiste em um número inteiro n, representando o tamanho do vetor A.
- A segunda linha de entrada contém n inteiros não negativos, representando os elementos do vetor A.
- Restrições:
  - $1 \le n \le 10^{6} $
  - $0 \le A[i] \le 10^6$

### Saída

- A saída consiste em uma única linha de n inteiros, representando os índices originais de cada elemento no vetor ordenado.

## Exemplos

<!-- load tests.toml --tests 3 -->
```py
>>>>>>>> INSERT
10
7 5 4 3 2 1 8 0 9 6
======== EXPECT
7 5 4 3 2 1 9 0 6 8
<<<<<<<< FINISH
```

```py
>>>>>>>> INSERT
50
41 18467 6334 26500 19169 15724 11478 29358 26962 24464 5705 28145 23281 16827 9961 491 2995 11942 4827 5436 32391 14604 3902 153 292 12382 17421 18716 19718 19895 5447 21726 14771 11538 1869 19912 25667 26299 17035 9894 28703 23811 31322 30333 17673 4664 15141 7711 28253 6868
======== EXPECT
0 23 24 15 34 16 22 45 18 19 30 10 2 49 47 39 14 6 33 17 25 21 32 46 5 13 38 26 44 1 27 4 28 29 35 31 12 41 9 36 37 3 8 11 48 40 7 43 42 20
<<<<<<<< FINISH
```
<!-- load -->
