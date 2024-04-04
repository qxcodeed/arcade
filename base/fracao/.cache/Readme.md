# L3 - @fracao - Implemente a classe fração reduzida

- Veja a versão online: [aqui.](https://github.com/qxcodeed/arcade/blob/master/base/fracao/Readme.md)
- Para programar na sua máquina (local/virtual) use:
  - `tko down ed fracao`
- Se não tem o `tko`, instale pelo [LINK](https://github.com/senapk/tko#tko).

---

## Intro

Implemente a classe fração e os métodos orientados no arquivo `fracao.hpp`.

## Draft

- Você deve implementar os métodos solicitados no arquivo `fracao.cpp`.
- Estude a interface da classe `Fracao` no arquivo `fracao.hpp` e veja a descrição dos métodos.
- Estude também a forma como ela foi construída para aprender mais sobre sobrecarga de operadores, construtores e métodos canônicos.
- A classe `main.cpp` já está implementada e você não deve alterá-la.
- A classe `fn.hpp` contém funções auxiliares para ajudar na implementação dos testes.

<!-- draft -->
- cpp
  - [fn.hpp](https://github.com/qxcodeed/arcade/blob/master/base/fracao/.cache/lang/cpp/fn.hpp)
  - [fracao.cpp](https://github.com/qxcodeed/arcade/blob/master/base/fracao/.cache/lang/cpp/fracao.cpp)
  - [fracao.hpp](https://github.com/qxcodeed/arcade/blob/master/base/fracao/.cache/lang/cpp/fracao.hpp)
  - [main.cpp](https://github.com/qxcodeed/arcade/blob/master/base/fracao/.cache/lang/cpp/main.cpp)

<!-- draft -->

## Tests

- As saídas devem ser realizadas com 2 casas decimais.

- Entrada
  - Lista de frações no formato `numerador/denominador`
- Saída
  - Lista de frações reduzidas no formato `numerador/denominador`
  - Lista ordenada pelo valor da fração.

```txt
>>>>>>>> 01
1/2 1/3 2/3 3/4 8/4 10/50 20/5 13/5 4/50 50/30
========
1/2 1/3 2/3 3/4 2/1 1/5 4/1 13/5 2/25 5/3
2/25 1/5 1/3 1/2 2/3 3/4 5/3 2/1 13/5 4/1
<<<<<<<<
```
