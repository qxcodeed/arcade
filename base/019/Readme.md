## ©07_tree_ Level_Order_Traversal
## @qxcode

![](__capa.jpg)
**Descrição da função**

Você recebe um ponteiro para a raiz de uma árvore binária. Você precisa imprimir o percurso da ordem de nível desta árvore. No percurso de ordem de nível, visitamos os nós, nível por nível, da esquerda para a direita. Você só precisa completar a função. Por exemplo:

    1
      \
       2
        \
         5
        /  \
       3    6
        \
         4  


Para a árvore acima, o percurso da ordem de nível é 1 -> 2 -> 5 -> 3 -> 6 -> 4.

**Formato de entrada**

A primeira linha contém um número inteiro n, o número de nós na árvore.
A próxima linha contém n inteiros separados por espaço, em que o inteiro i indica o valor (data) do no[i]

**Formato de saída**

Imprima os valores em uma única linha separada por um espaço.

## Testes

```
>>>>>>>> 01
6
1 2 5 3 6 4
========
1 2 5 3 6 4 
<<<<<<<<

>>>>>>>> 02
116
37 23 108 59 86 64 94 14 105 17 111 65 55 31 79 97 78 25 50 22 66 46 104 98 81 90 68 40 103 77 74 18 69 82 41 4 48 83 67 6 2 95 54 100 99 84 34 88 27 72 32 62 9 56 109 115 33 15 91 29 85 114 112 20 26 30 93 96 87 42 38 60 7 73 35 12 10 57 80 13 52 44 16 70 8 39 107 106 63 24 92 45 75 116 5 61 49 101 71 11 53 43 102 110 1 58 36 28 76 47 113 21 89 51 19 3
========
37 23 108 14 31 59 111 4 17 25 34 55 86 109 115 2 6 15 22 24 27 32 35 50 56 64 94 110 114 116 1 3 5 9 16 18 26 29 33 36 46 54 57 62 65 90 105 112 7 12 20 28 30 40 48 52 58 60 63 79 88 91 97 107 113 8 10 13 19 21 38 41 47 49 51 53 61 78 81 87 89 93 95 104 106 11 39 42 66 80 82 92 96 98 44 68 83 103 43 45 67 77 84 100 74 85 99 101 69 75 102 72 76 70 73 71 
<<<<<<<<

>>>>>>>> 03
6
4 1 8 10 9 3
========
4 1 8 3 10 9 
<<<<<<<<

>>>>>>>> 04
7
3 5 2 1 4 6 7
========
3 2 5 1 4 6 7 
<<<<<<<<
```
