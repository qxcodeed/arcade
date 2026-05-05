# Caminho até o nó

<!-- toch -->
[Descrição](#descrição) | [Estudo de caso](#estudo-de-caso) | [Exemplos](#exemplos)
-- | -- | --
<!-- toch -->

![_](assets/cover.jpg)

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

## Estudo de caso

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

## Exemplos

<!-- load tests.toml --tests 3 -->
```py
>>>>>>>> INSERT
4 # #
4
======== EXPECT
Arvore:
4
Caminho: x
<<<<<<<< FINISH
```

```py
>>>>>>>> INSERT
1 # 0 # # 
0
======== EXPECT
Arvore:
╭───#
1
╰───0
Caminho: rx
<<<<<<<< FINISH
```

```py
>>>>>>>> INSERT
4 # 8 2 # # # 
2
======== EXPECT
Arvore:
╭───#
4
│   ╭───2
╰───8
    ╰───#
Caminho: rlx
<<<<<<<< FINISH
```
<!-- load -->
