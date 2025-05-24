# Implemente a classe ponto

## Intro

Implemente a classe ponto e faça a equação da reta.

## Draft

- O único arquivo que você deve modificar é `point.cpp`.
  - Você deve implementar o construtor, o método `dist` e os métodos para calcular a inclinação da reta e o ponto mais próximo.
- Estude o arquivo `point.hpp` para entender a interface da classe e aprender como usar os métodos.
- O arquivo `main.cpp` contém o código que lê os pontos e chama os métodos da classe ponto, além de imprimir os resultados.
- O arquivo `fn.hpp` contém funções auxiliares para ler e imprimir pontos.

<!-- links .cache/draft -->
- cpp
  - [fn.hpp](https://github.com/qxcodeed/arcade/blob/master/base/ponto/.cache/draft/cpp/fn.hpp)
  - [main.cpp](https://github.com/qxcodeed/arcade/blob/master/base/ponto/.cache/draft/cpp/main.cpp)
  - [point.cpp](https://github.com/qxcodeed/arcade/blob/master/base/ponto/.cache/draft/cpp/point.cpp)
  - [point.hpp](https://github.com/qxcodeed/arcade/blob/master/base/ponto/.cache/draft/cpp/point.hpp)
<!-- links -->

## Testes

- Entrada
  - 1a linha: ponto de origem no formato (x, y).
  - 2a linha: lista de N pontos no formato (x, y).
- Saída
  - Todas as saídas devem ser formatadas com 2 casas decimais.
  - 1a linha: inclinação da reta de cada ponto de origem para cada ponto da lista.
  - 2a linha: vetor com as distâncias do ponto de origem para cada ponto da lista.
  - 3a linha: índice do ponto da lista mais próximo do ponto de origem.

```bash
>>>>>>>>
(0,0)
(1,1) (2,2) (3,3)
========
1.00 1.00 1.00
1.41 2.83 4.24
0
<<<<<<<<

>>>>>>>>
(5.2,3.1)
(1.2,1.3) (2.2,2.3) (3.3,5.9)
========
0.50 0.33 -1.00
4.47 3.16 2.83
2
<<<<<<<<
```
