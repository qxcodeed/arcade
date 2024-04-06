# L1 - implementando lista @ligada simples sem cabeça e rabo

<!-- toch -->
[Intro](#intro) | [Guide](#guide) | [Draft](#draft) | [Shell](#shell)
-- | -- | -- | --
<!-- toch -->

![_](cover.jpg)

## Intro

Seja a uma lista ligada sem cabeça e sem rabo. Implemente as funções de:

- push_back
- push_front
- pop_back
- pop_front
- size
- clear

## Guide

- Faça os métodos um a um na ordem dos testes.
- Não tente passar para o próximo teste sem que o atual esteja passando.
- Se quiser comentar um teste, use `//` no início da linha correspondente na main do arquivo `main.cpp`.
- Se um teste falhar, corrija o método correspondente e siga para o próximo teste.
- Para rodar os testes, passe os arquivos main.cpp e list.cpp para o `tko`.

```bash
tko run main.cpp list.cpp cases.tio
```

- Se quiser rodar sua própria main, use o `tko` com o arquivo `list.cpp` e sua main.

```bash
tko run list.cpp aluno.cpp cases.tio
```

Sendo a sua main algo como:

```cpp
#include "list.hpp"
using namespace std;

int main() {
    LinkedList ll;
    ll.push_back(1);
    std::cout << ll << std::endl;
}
```


## Draft

- Você deve implementar os métodos no arquivo `list.cpp`.
- Crie os métodos auxiliares que precisar dentro do `list.cpp`.
- O arquivo `list.hpp` contém as estruturas e métodos já implementados.
- A `main.cpp` já faz a leitura dos testes e invoca os métodos adequados da classe.
- A `fn.hpp` é uma biblioteca auxiliar de processamento de string em c++.

<!-- draft -->
- cpp
  - [fn.hpp](.cache/lang/cpp/fn.hpp)
  - [list.cpp](.cache/lang/cpp/list.cpp)
  - [list.hpp](.cache/lang/cpp/list.hpp)
  - [main.cpp](.cache/lang/cpp/main.cpp)
  - [student.cpp](.cache/lang/cpp/student.cpp)

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
