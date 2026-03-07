# Mostrando a árvore formatada

<!-- toch -->
[Descrição](#descrição) | [Testes](#testes)
-- | --
<!-- toch -->

![_](https://raw.githubusercontent.com/qxcodeed/arcade/master/base/formatada/cover.jpg)

## Descrição

- Leia a string que representa a árvore serializada utilizando o código que você implementou no exercício @serial para construir sua árvore.
- Crie um método recursivo chamado `my_show()` que recebe um nó e um inteiro `depth` (inicialmente 0) e imprime a árvore formatada.
- Utilize o espaçamento de "...." para cada nível de profundidade do nó.
- Faça a impressão usando o percorrimento in-order.
- Se o nó possuir pelos menos um filho não nulo, chame a recursão para ambos os filhos e imprima o filho nulo como um #
- Se o nó não possuir filhos, imprima apenas o valor do nó.

- Saída
  - Impressão da função 'BShow' que já vem no rascunho, seguido da sua função de impressão `MyShow()`.

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
....#
1
....0
<<<<<<<< FINISH


>>>>>>>> INSERT tres
4 # 8 2 # # # 
======== EXPECT
╭───#
4
│   ╭───2
╰───8
    ╰───#
....#
4
........2
....8
........#
<<<<<<<< FINISH


>>>>>>>> INSERT quatro
0 9 4 # # # 5 # # 
======== EXPECT
    ╭───4
╭───9
│   ╰───#
0
╰───5
........4
....9
........#
0
....5
<<<<<<<< FINISH


>>>>>>>> INSERT cinco
0 4 # # 2 0 # # 3 # # 
======== EXPECT
╭───4
0
│   ╭───0
╰───2
    ╰───3
....4
0
........0
....2
........3
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
........0
....0
........#
2
........#
....3
............#
........7
............9
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
........7
....8
............#
........4
............6
1
........0
....5
............#
........9
................2
............3
................#
<<<<<<<< FINISH

```
