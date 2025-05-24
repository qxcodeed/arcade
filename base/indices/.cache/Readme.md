# Índices originais

<!-- toch -->
[Intro](#intro) | [Draft](#draft) | [Tests](#tests)
-- | -- | --
<!-- toch -->

## Intro

Você recebe um vetor A de inteiros não negativos de tamanho n. Sua tarefa é ordenar o vetor em ordem crescente e imprimir os índices originais dos elementos.

Considere o vetor `A = {4,5,3,7,1}`

Após a ordenação, o vetor ordenado será: `A = {1,3,4,5,7}`.

A saída deve ser os índices originais dos elementos do vetor ordenado: `4 2 0 1 3`

**NOTA:** A indexação da vetor começa com 0.

## Draft

- Você deve implementar um algoritmo de ordenação e a função `originalIndices` no arquivo `main.cpp`.

<!-- links .cache/draft -->
- cpp
  - [main.cpp](https://github.com/qxcodeed/arcade/blob/master/base/indices/.cache/draft/cpp/main.cpp)
<!-- links -->

## Tests

### Entrada

- A primeira linha de entrada consiste em um número inteiro n, representando o tamanho do vetor A.
- A segunda linha de entrada contém n inteiros não negativos, representando os elementos do vetor A.
- Restrições:
  - $1 \le n \le 10^{6} $
  - $0 \le A[i] \le 10^6$

### Saída

- A saída consiste em uma única linha de n inteiros, representando os índices originais de cada elemento no vetor ordenado.

```txt
>>>>>>>>
5
4 5 3 7 1
========
4 2 0 1 3
<<<<<<<<
```
