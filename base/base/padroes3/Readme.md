# Descobrindo quantos pontos

<!-- toch -->
[Intro](#intro) | [Draft](#draft) | [Tests](#tests)
-- | -- | --
<!-- toch -->

## Intro

Considere as seguintes sequências de figuras geométricas:

![Padrões](Padroes.png)

Dado dois inteiros $3 \leq n \leq 20$ e $ 1 \leq m \leq 40$, encontre o número de pontos da m-ésima figura da sequência $F_n$. Por exemplo, a segunda figura da sequência $F_3$ é formada por 3 pontos.

## Draft

- Você deve implementar de forma recursiva a função `calculaPontos` no arquivo `main.cpp`.

<!-- links .cache/draft -->
- cpp
  - [main.cpp](.cache/draft/cpp/main.cpp)
<!-- links -->

## Tests

- Entrada
  - A entrada consiste em uma única linha que contém dois números inteiros, n e m. Esses números representam, respectivamente, a sequência e a posição m-ésima na sequência $F_n$.

- Saída
  - A saída é composta por uma única linha contendo o número total de pontos.

```txt
>>>>>>>>
6 2
========
6
<<<<<<<<
```
