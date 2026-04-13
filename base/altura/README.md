# Altura e profundidade da árvore

<!-- toch -->
[Descrição](#descrição) | [Testes](#testes)
-- | --
<!-- toch -->

![_](assets/cover.jpg)

## Descrição

Dado o modelo de árvore utilizado nas questões anteriores, implemente os seguintes métodos.

```cpp
Node * find(int value); //retorna o nó dado o valor ou retorna null
int getAltura(Node * node);
int getProfundidade(Node * node);
```

- Entrada
  - linha 1: o serial de uma árvore
  - linha 2: uma lista de valores de nó
- Saída
  - Para cada nó da lista, um nó por linha, altura e profundidade do nó ou -1 se o nó não for encontrado

![_](assets/__altura.jpg)

## Testes

```txt
>>>>>>>> INSERT 01 um
4 # # 
4
======== EXPECT
Arvore:
4
Altura: 1, Profundidade: 1
<<<<<<<< FINISH

>>>>>>>> INSERT 02 dois
1 # 0 # # 
0 1
======== EXPECT
Arvore:
╭───#
1
╰───0
Altura: 1, Profundidade: 2
Altura: 2, Profundidade: 1
<<<<<<<< FINISH

>>>>>>>> INSERT 03 tres
4 # 8 2 # # # 
2 8 4
======== EXPECT
Arvore:
╭───#
4
│   ╭───2
╰───8
    ╰───#
Altura: 1, Profundidade: 3
Altura: 2, Profundidade: 2
Altura: 3, Profundidade: 1
<<<<<<<< FINISH

>>>>>>>> INSERT 04 quatro
0 9 4 # # # 5 # # 
5 4 3 0 9
======== EXPECT
Arvore:
    ╭───4
╭───9
│   ╰───#
0
╰───5
Altura: 1, Profundidade: 2
Altura: 1, Profundidade: 3
-1
Altura: 3, Profundidade: 1
Altura: 2, Profundidade: 2
<<<<<<<< FINISH

>>>>>>>> INSERT 05 cinco
8 4 # # 2 0 # # 3 # # 
0 4 8 2 3 7
======== EXPECT
Arvore:
╭───4
8
│   ╭───0
╰───2
    ╰───3
Altura: 1, Profundidade: 3
Altura: 1, Profundidade: 2
Altura: 3, Profundidade: 1
Altura: 2, Profundidade: 2
Altura: 1, Profundidade: 3
-1
<<<<<<<< FINISH

>>>>>>>> INSERT 06 seis
2 1 0 # # # 3 # 7 # 9 # # 
9 7 3 6 1 2 0
======== EXPECT
Arvore:
    ╭───0
╭───1
│   ╰───#
2
│   ╭───#
╰───3
    │   ╭───#
    ╰───7
        ╰───9
Altura: 1, Profundidade: 4
Altura: 2, Profundidade: 3
Altura: 3, Profundidade: 2
-1
Altura: 2, Profundidade: 2
Altura: 4, Profundidade: 1
Altura: 1, Profundidade: 3
<<<<<<<< FINISH

>>>>>>>> INSERT 07 dez
1 8 7 # # 4 # 6 # # 5 0 # # 9 # 3 2 # # # 
1 2 3 4 5 6 7 8 9
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
Altura: 5, Profundidade: 1
Altura: 1, Profundidade: 5
Altura: 2, Profundidade: 4
Altura: 2, Profundidade: 3
Altura: 4, Profundidade: 2
Altura: 1, Profundidade: 4
Altura: 1, Profundidade: 3
Altura: 3, Profundidade: 2
Altura: 3, Profundidade: 3
<<<<<<<< FINISH

```
