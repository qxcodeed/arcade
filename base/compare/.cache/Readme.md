# Mostrando a árvore formatada

<!-- toch -->
[Descrição](#descrição) | [Testes](#testes)
-- | --
<!-- toch -->

![_](https://raw.githubusercontent.com/qxcodeed/arcade/master/base/compare/cover.jpg)

## Descrição

- Compare duas árvores binárias e retorne se a primeira é menor, maior ou igual à segunda.
- Utilize a seguinte estratégia:
- Percorra simultaneamente ambas as árvores (DFS):
  - compare valor do nó atual;
  - se diferentes, retorna imediatamente (< ou >);
  - se iguais, prossiga para a subárvore esquerda, depois direita;
  - se nenhuma diferença e ambas terminam null ao mesmo tempo: são iguais.

- Saída:
  - `menor` se a primeira árvore for menor que a segunda;
  - `maior` se a primeira árvore for maior que a segunda;
  - `iguais` se ambas forem iguais.

## Testes

```txt
>>>>>>>> INSERT um
4 # # 
4 # # 
======== EXPECT
4
4
iguais
<<<<<<<< FINISH


>>>>>>>> INSERT dois
1 # 0 # # 
1 # 1 # # 
======== EXPECT
╭───#
1
╰───0
╭───#
1
╰───1
menor
<<<<<<<< FINISH

>>>>>>>> INSERT dois
1 # 2 # # 
1 # 1 # # 
======== EXPECT
╭───#
1
╰───2
╭───#
1
╰───1
maior
<<<<<<<< FINISH

>>>>>>>> INSERT dois
1 2 # # # 
1 # 2 # # 
======== EXPECT
╭───2
1
╰───#
╭───#
1
╰───2
maior
<<<<<<<< FINISH

>>>>>>>> INSERT dois
1 # 2 # # 
1 2 # # # 
======== EXPECT
╭───#
1
╰───2
╭───2
1
╰───#
menor
<<<<<<<< FINISH

>>>>>>>> INSERT tres
4 # 8 2 # # # 
4 # 8 2 # # # 
======== EXPECT
╭───#
4
│   ╭───2
╰───8
    ╰───#
╭───#
4
│   ╭───2
╰───8
    ╰───#
iguais
<<<<<<<< FINISH

>>>>>>>> INSERT tres
4 # 8 2 # # # 
4 8 2 # # # #
======== EXPECT
╭───#
4
│   ╭───2
╰───8
    ╰───#
    ╭───2
╭───8
│   ╰───#
4
╰───#
menor
<<<<<<<< FINISH

>>>>>>>> INSERT quatro
0 9 4 # # # 5 # # 
0 8 4 # # # 5 # # 
======== EXPECT
    ╭───4
╭───9
│   ╰───#
0
╰───5
    ╭───4
╭───8
│   ╰───#
0
╰───5
maior
<<<<<<<< FINISH
