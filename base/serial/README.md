# Lendo uma árvore a partir de um serial

<!-- toch -->
[Descrição](#descrição) | [Testes](#testes)
-- | --
<!-- toch -->

![_](cover.jpg)

## Descrição

- Leia a string que representa a árvore serializada.
- Você deve construir a árvore a partir da string implementando corretamente o construtor do código de partida.
- Você pode entender a lógica de serialização no seguinte [link para explicação](https://www.geeksforgeeks.org/serialize-deserialize-binary-tree/).
- A saída é a árvore percorrida in-order, mas já está implementado no código de partida.
- Baixe o código de rascunho e implemente a função `create` para construir a árvore a partir da string serializada.

## Testes

```txt
>>>>>>>> INSERT um
4 # # 
======== EXPECT
4
<<<<<<<< FINISH


>>>>>>>> INSERT dois
1 # 0 # # 
======== EXPECT
╭───#
1
╰───0
<<<<<<<< FINISH


>>>>>>>> INSERT tres
4 # 8 2 # # # 
======== EXPECT
╭───#
4
│   ╭───2
╰───8
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
<<<<<<<< FINISH


>>>>>>>> INSERT cinco
0 4 # # 2 0 # # 3 # # 
======== EXPECT
╭───4
0
│   ╭───0
╰───2
    ╰───3
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
<<<<<<<< FINISH


>>>>>>>> INSERT dez
1 8 7 # # 4 # 6 # # 5 0 # # 9 # 3 2 # # # 
======== EXPECT
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
<<<<<<<< FINISH

```
