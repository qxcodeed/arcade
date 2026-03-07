# Clonando a árvore

<!-- toch -->
[Descrição](#descrição) | [Testes](#testes)
-- | --
<!-- toch -->

![_](https://raw.githubusercontent.com/qxcodeed/arcade/master/base/clonar/cover.jpg)

## Descrição

- Inverta uma árvore binária, ou seja, troque os nós filhos esquerdo e direito de cada nó.

- Saída
  - Impressão da função 'BShow' que já vem no rascunho.

## Testes

```txt
>>>>>>>> INSERT um
4 # # 
======== EXPECT
original:
4
clone:
4
<<<<<<<< FINISH


>>>>>>>> INSERT dois
1 # 0 # # 
======== EXPECT
original:
╭───#
1
╰───0
clone:
╭───#
1
╰───0
<<<<<<<< FINISH


>>>>>>>> INSERT tres
4 # 8 2 # # # 
======== EXPECT
original:
╭───#
4
│   ╭───2
╰───8
    ╰───#
clone:
╭───#
4
│   ╭───2
╰───8
    ╰───#
<<<<<<<< FINISH


>>>>>>>> INSERT quatro
0 9 4 # # # 5 # # 
======== EXPECT
original:
    ╭───4
╭───9
│   ╰───#
0
╰───5
clone:
    ╭───4
╭───9
│   ╰───#
0
╰───5
<<<<<<<< FINISH


>>>>>>>> INSERT cinco
0 4 # # 2 0 # # 3 # # 
======== EXPECT
original:
╭───4
0
│   ╭───0
╰───2
    ╰───3
clone:
╭───4
0
│   ╭───0
╰───2
    ╰───3
<<<<<<<< FINISH


>>>>>>>> INSERT seis
2 0 0 # # # 3 # 7 # 9 # # 
======== EXPECT
original:
    ╭───0
╭───0
│   ╰───#
2
│   ╭───#
╰───3
    │   ╭───#
    ╰───7
        ╰───9
clone:
    ╭───0
╭───0
│   ╰───#
2
│   ╭───#
╰───3
    │   ╭───#
    ╰───7
        ╰───9
<<<<<<<< FINISH

```
