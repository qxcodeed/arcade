# L1 - implementando lista @ligada simples sem cabeça e rabo

- Veja a versão online: [aqui.](https://github.com/qxcodeed/arcade/blob/master/base/ligada/Readme.md)
- Para programar na sua máquina (local/virtual) use:
  - `tko down ed ligada`
- Se não tem o `tko`, instale pelo [LINK](https://github.com/senapk/tko#tko).

---

![_](https://raw.githubusercontent.com/qxcodeed/arcade/master/base/ligada/cover.jpg)

<!-- toc -->
- [Draft](#draft)
- [Shell](#shell)
<!-- toc -->

Seja a uma lista ligada sem cabeça e sem rabo. Implemente as funções de:

- push_back
- push_front
- pop_back
- pop_front
- size
- clear

## Draft

- Você deve implementar os métodos no arquivo `list.cpp`.
- Crie os métodos auxiliares que precisar dentro do `list.cpp`.
- O arquivo `list.hpp` contém as estruturas e métodos já implementados.
- A `main.cpp` já faz a leitura dos testes e invoca os métodos adequados da classe.
- A `fn.hpp` é uma biblioteca auxiliar de processamento de string em c++.

<!-- draft -->
- cpp
  - [fn.hpp](https://github.com/qxcodeed/arcade/blob/master/base/ligada/.cache/lang/cpp/fn.hpp)
  - [list.cpp](https://github.com/qxcodeed/arcade/blob/master/base/ligada/.cache/lang/cpp/list.cpp)
  - [list.hpp](https://github.com/qxcodeed/arcade/blob/master/base/ligada/.cache/lang/cpp/list.hpp)
  - [main.cpp](https://github.com/qxcodeed/arcade/blob/master/base/ligada/.cache/lang/cpp/main.cpp)

<!-- draft -->

## Shell

```bash

#TEST_CASE init
$show
[]
$end

```

```bash
#TEST_CASE push_front
$push_front 1 2 3 4
$show
[4, 3, 2, 1]
$push_front 9 6
$show
[6, 9, 4, 3, 2, 1]
$end
```

```bash
#TEST_CASE size
$size
0
$push_front 4
$show
[4]
$size
1
$push_front 3 2 1
$show
[1, 2, 3, 4]
$size
4
$end
```

```bash
#TEST_CASE clear
$push_front 1 2 3 4
$show
[4, 3, 2, 1]
$clear
$show
[]
$clear
$show
[]
$push_front 1 2 3 4
$show
[4, 3, 2, 1]
$end
```

```bash
#TEST_CASE push_back
$push_back 1 2 3 4
$show
[1, 2, 3, 4]
$push_back 1 2 3 4
$show
[1, 2, 3, 4, 1, 2, 3, 4]
$push_front 0 3
$show
[3, 0, 1, 2, 3, 4, 1, 2, 3, 4]
$end

```

```bash
#TEST_CASE pop_front
$push_back 1 3 4 5
$show
[1, 3, 4, 5]
$pop_front
$show
[3, 4, 5]
$pop_front
$show
[4, 5]
$pop_front
$show
[5]
$pop_front
$show
[]
$pop_front
$show
[]
$end
```

```bash
#TEST_CASE pop_back
$push_back 1 3 4 5
$show
[1, 3, 4, 5]
$pop_back
$show
[1, 3, 4]
$pop_back
$show
[1, 3]
$pop_back
$show
[1]
$pop_back
$show
[]
$pop_back
$show
[]
$end
```
