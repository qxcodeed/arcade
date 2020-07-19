## ©07_tree_ TopView
## @qxcode

![](__capa.jpg)
**Descrição da função**

Você recebe um ponteiro para a raiz de uma árvore binária. Imprima a vista superior da árvore binária.
Vista superior significa que quando você olha a árvore de cima para os nós, o que verá será chamado de vista superior da árvore. Veja o exemplo abaixo.
Você só precisa completar a função.
Por exemplo :

  1
    \
     2
      \
       5
      /  \
     3    6
      \
       4

Top View : 1 -> 2 -> 5 -> 6

**Formato de entrada**

A primeira linha contém um número inteiro n, o número de nós na árvore.
A próxima linha contém n inteiros separados por espaço, em que o inteiro i indica o valor (data) do no[i]

**Formato de saída**

Imprima os valores em uma única linha separada por espaço.

## Testes

```
>>>>>>>> 01
6
1 2 5 3 6 4
========
1 2 5 6
<<<<<<<<

>>>>>>>> 02
116
37 23 108 59 86 64 94 14 105 17 111 65 55 31 79 97 78 25 50 22 66 46 104 98 81 90 68 40 103 77 74 18 69 82 41 4 48 83 67 6 2 95 54 100 99 84 34 88 27 72 32 62 9 56 109 115 33 15 91 29 85 114 112 20 26 30 93 96 87 42 38 60 7 73 35 12 10 57 80 13 52 44 16 70 8 39 107 106 63 24 92 45 75 116 5 61 49 101 71 11 53 43 102 110 1 58 36 28 76 47 113 21 89 51 19 3
========
1 2 4 14 23 37 108 111 115 116 83 84 85
<<<<<<<<
```
