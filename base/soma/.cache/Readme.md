# Soma e Mínimo Recursivos

<!-- toch -->
[Descrição](#descrição) | [Testes](#testes)
-- | --
<!-- toch -->

![_](https://raw.githubusercontent.com/qxcodeed/arcade/master/base/soma/cover.jpg)

## Descrição

Implemente os métodos solicitados no rascunho de acordo com os comentários no código. Essa NÃO é uma árvore binária de busca. É uma árvore binária genérica no qual os nós podem conter quaisquer valores.

## Testes

```txt
>>>>>>>> INSERT 01 um
4 # # 
======== EXPECT
Arvore:
4
Soma: 4, Minimo: 4
<<<<<<<< FINISH


>>>>>>>> INSERT 02 dois
1 # 0 # # 
======== EXPECT
Arvore:
╭───#
1
╰───0
Soma: 1, Minimo: 0
<<<<<<<< FINISH


>>>>>>>> INSERT 03 tres
4 # 8 2 # # # 
======== EXPECT
Arvore:
╭───#
4
│   ╭───2
╰───8
    ╰───#
Soma: 14, Minimo: 2
<<<<<<<< FINISH


>>>>>>>> INSERT 04 quatro
0 9 4 # # # 5 # # 
======== EXPECT
Arvore:
    ╭───4
╭───9
│   ╰───#
0
╰───5
Soma: 18, Minimo: 0
<<<<<<<< FINISH


>>>>>>>> INSERT 05 cinco
0 4 # # 2 0 # # -3 # # 
======== EXPECT
Arvore:
╭───4
0
│   ╭───0
╰───2
    ╰───-3
Soma: 3, Minimo: -3
<<<<<<<< FINISH


>>>>>>>> INSERT 06 seis
2 0 5 # # # 3 # 7 # -9 # # 
======== EXPECT
Arvore:
    ╭───5
╭───0
│   ╰───#
2
│   ╭───#
╰───3
    │   ╭───#
    ╰───7
        ╰───-9
Soma: 8, Minimo: -9
<<<<<<<< FINISH


>>>>>>>> INSERT 07 dez
1 8 7 # # 4 # 6 # # 5 0 # # 9 # 3 2 # # # 
======== EXPECT
Arvore:
    ╭───7
╭───8
│   │   ╭───#
│   ╰───4
│       ╰───6
1
│   ╭───0
╰───5
    │   ╭───#
    ╰───9
        │   ╭───2
        ╰───3
            ╰───#
Soma: 45, Minimo: 0
<<<<<<<< FINISH
```
