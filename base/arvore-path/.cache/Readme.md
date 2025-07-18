# Caminho até o nó

<!-- toch -->
[Descrição](#descrição) | [Exemplo](#exemplo) | [Testes](#testes)
-- | -- | --
<!-- toch -->

![_](https://raw.githubusercontent.com/qxcodeed/arcade/master/base/arvore-path/cover.jpg)

## Descrição

- Entrada
  - linha 1: o serial de uma árvore binária
  - linha 2: um valor de nó
- Saída
  - se o valor existe:
    - mostre o caminho da raiz até o nó,
    - indicando 'l' ou 'r' se o caminho é pelo filho da esquerda ou da direita.
    - ponha um 'x' para quando achar o nó.
  - Se o valor não existir na árvore
    - imprima "!"
- Limitação
  - Você deve percorrer a árvore UMA única vez para obter os caminhos e montar o caminho através do retorno da função.

## Exemplo

Para encontrar o 2 na árvore abaixo, seguimos o caminho `rrrlx`

```c
//serial
1 8 7 # # 4 # 6 # # 5 0 # # 9 # 3 2 # # #

//bshow()
    ┌───7
┌───8
│   │   ┌───#
│   └───4
│       └───6
1
│   ┌───0
└───5
    │   ┌───#
    └───9
        │   ┌───2
        └───3
            └───#
```

```cpp
//a função recursiva find deve retornar uma sequencia o path até o destino com x no final
string find_path(Node * root, int value);
```

## Testes

```txt
>>>>>>>> 01 um
4 # #
4
========
Arvore:
4
Caminho: x
<<<<<<<<

>>>>>>>> 02 dois
1 # 0 # # 
0
========
Arvore:
╭───#
1
╰───0
Caminho: rx
<<<<<<<<

>>>>>>>> 03 tres
4 # 8 2 # # # 
2
========
Arvore:
╭───#
4
│   ╭───2
╰───8
    ╰───#
Caminho: rlx
<<<<<<<<

>>>>>>>> 04 not found
0 9 4 # # # 5 # # 
7
========
Arvore:
    ╭───4
╭───9
│   ╰───#
0
╰───5
Caminho: !
<<<<<<<<

```
