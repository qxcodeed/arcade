## ©07_tree_ Level_Order_Traversal
## @qxcode

![](__capa.jpg)
**Descrição da função**

Você recebe um ponteiro para a raiz da árvore de busca binária e dois valores v1 e v2. Você precisa retornar o menor ancestral comum de v1 e v2 na árvore de busca binária.


    2
   /  \
  1    3
      /  \
     4    5
           \
            6  


Para a árvore acima, o menor ancestral comum dos nós 4 e 6 é o nó 3. Nó 3 é o nó mais baixo que possui nós 4 e 6 como descendentes.

**Formato de entrada**

A primeira linha contém um número inteiro n, o número de nós na árvore.
A próxima linha contém n inteiros separados por espaço, em que o inteiro i indica o valor (data) do no[i].
A terceira linha contém dois inteiros separados por espaço v1 e v2.

**Formato de saída**

retorne um ponteiro para o nó que é o menor ancestral comum de v1 e v2.

## Testes

```
>>>>>>>> 01
6
4 2 3 1 7 6
1 7
========
4
<<<<<<<<

>>>>>>>> 02
11
9 3 5 1 8 12 16 11 2 4 6
11 1
========
9
<<<<<<<<

>>>>>>>> 03
2
1 2
1 2
========
1
<<<<<<<<

>>>>>>>> 04
7
3 5 2 1 4 6 7
4 7
========
5
<<<<<<<<
```
