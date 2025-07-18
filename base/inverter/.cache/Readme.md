# Inverter a árvore

<!-- toch -->
[Descrição](#descrição) | [Testes](#testes)
-- | --
<!-- toch -->

![_](https://raw.githubusercontent.com/qxcodeed/arcade/master/base/inverter/cover.jpg)

## Descrição

- Inverta uma árvore binária, ou seja, troque os nós filhos esquerdo e direito de cada nó.

- Saída
  - Impressão da função 'BShow' que já vem no rascunho.

## Testes

```txt
>>>>>>>> INSERT um
4 # # 
======== EXPECT
4
4
<<<<<<<< FINISH


>>>>>>>> INSERT dois
1 # 0 # # 
======== EXPECT
╭───#
1
╰───0
╭───0
1
╰───#
<<<<<<<< FINISH


>>>>>>>> INSERT tres
4 # 8 2 # # # 
======== EXPECT
╭───#
4
│   ╭───2
╰───8
    ╰───#
    ╭───#
╭───8
│   ╰───2
4
╰───#
<<<<<<<< FINISH


>>>>>>>> INSERT quatro
0 9 4 # # # 5 # # 
======== EXPECT
    ╭───4
╭───9
│   ╰───#
0
╰───5
╭───5
0
│   ╭───#
╰───9
    ╰───4
<<<<<<<< FINISH


>>>>>>>> INSERT cinco
0 4 # # 2 0 # # 3 # # 
======== EXPECT
╭───4
0
│   ╭───0
╰───2
    ╰───3
    ╭───3
╭───2
│   ╰───0
0
╰───4
<<<<<<<< FINISH


>>>>>>>> INSERT seis
2 0 0 # # # 3 # 7 # 9 # # 
======== EXPECT
    ╭───0
╭───0
│   ╰───#
2
│   ╭───#
╰───3
    │   ╭───#
    ╰───7
        ╰───9
        ╭───9
    ╭───7
    │   ╰───#
╭───3
│   ╰───#
2
│   ╭───#
╰───0
    ╰───0
<<<<<<<< FINISH

```
