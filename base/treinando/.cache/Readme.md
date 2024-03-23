# L1 - @treinando recursão com vetores | student

<!-- toch -->
[Intro](#intro) | [Atenção](#atenção) | [Draft](#draft) | [Shell](#shell)
-- | -- | -- | --
<!-- toch -->

![_](https://raw.githubusercontent.com/qxcodeed/arcade/master/base/treinando/cover.jpg)

## Intro

- Dado um vetor de inteiros, implemente funções recursivas para as seguintes operações.
- `lib.cpp`: onde você fará a implementação dos métodos.
- `lib.hpp`: A descrição dos métodos a ser implementados.
- `fn.hpp`: arquivo auxiliar para realizar leitura e escrita de dados.
- `main.cpp`: arquivo que faz a leitura das solicitações, invoca as funções e imprime as respostas.

## Atenção

- Algumas funções vão precisar que você crie funções recursivas auxiliares.
- Ao terminar de implentar uma função execute os testes e só vá para próxima após passar nos testes.
- Na seção Shell, você pode ver os testes que serão executados.
- Na seção Draft, você pode baixar manualmente os arquivos. Mas é mais prático utilizar o `tko`.
- No arquivo `lib.cpp`, o método `tostr` está implmentado como modelo.
- A seguir, o arquivo `lib.hpp` para consulta:

<!-- load src/cpp/lib.hpp fenced:cpp -->

```cpp
//lib.hpp
#pragma once
#include <iostream>

namespace alu {
    // init: aponta para o primeiro elemento do vetor
    // end: aponta para uma posição depois do último elemento do vetor
    // converte o vetor para texto no formato [1, 2, 3, 4]
    std::string tostr(int * init, int * end);

    // converte o vetor para texto, porém ao contrário
    std::string torev(int * init, int * end);

    // inverte os elementos do vetor inplace
    void reverse(int * init, int * end);

    // soma os elementos do vetor
    int sum(int * init, int * end);

    // multiplica os elementos do vetor
    // retorne 1, se o vetor estiver vazio
    int mult(int * init, int * end);

    // DESAFIO
    // retorne a posição do menor elemento do vetor
    int min(int * init, int * end);

} // namespace alu
```

<!-- load -->

## Draft

<!-- draft -->
- cpp
  - [fn.hpp](https://github.com/qxcodeed/arcade/blob/master/base/treinando/.cache/lang/cpp/fn.hpp)
  - [lib.cpp](https://github.com/qxcodeed/arcade/blob/master/base/treinando/.cache/lang/cpp/lib.cpp)
  - [lib.hpp](https://github.com/qxcodeed/arcade/blob/master/base/treinando/.cache/lang/cpp/lib.hpp)
  - [main.cpp](https://github.com/qxcodeed/arcade/blob/master/base/treinando/.cache/lang/cpp/main.cpp)

<!-- draft -->

___

## Shell
  
```bash
#__case tostr

$read
$tostr
[]

$read 4
$tostr
[4]

$read 4 5
$tostr
[4, 5]

$read 4 5 6
$tostr
[4, 5, 6]
$end
```

```bash
#__case torev

$read
$torev
[]

$read 4
$torev
[4]

$read 4 5
$torev
[5, 4]

$read 4 5 6
$torev
[6, 5, 4]

$end
```

```bash
#__case reverse

$read
$reverse
$tostr
[]

$read 4
$reverse
$tostr
[4]

$read 4 5
$reverse
$tostr
[5, 4]

$read 4 5 6
$reverse
$tostr
[6, 5, 4]

$end
```

```bash
#__case sum
$read
$sum
0

$read 4
$sum
4

$read 4 5
$sum
9

$read 4 5 6
$sum
15

$end
```

```bash
#__case mult
$read
$mult
1

$read 4
$mult
4

$read 4 5
$mult
20

$read 4 5 6
$mult
120

$end
```

```bash
#__case min
$read
$min
-1

$read 4
$min
0

$read 4 5
$min
0

$read 5 4
$min
1

$read 4 5 6
$min
0

$read 5 4 6
$min
1

$read 5 6 4
$min
2

$read 4 3 5 1 9 4 5
$min
3

$end
```
