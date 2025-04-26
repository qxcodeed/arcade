# Magic Search com busca binária

Dado uma lista de elementos ordenados, com possibilidade de repetição de valores, utilize uma variação da busca binária para retornar:

- Se o elemento existir, retorne a posição da última ocorrência.
- Se ele não existir, retorne a posição onde ele deveria ser inserido na lista ordenada.

Seu algoritmo deve utilizar a busca binária para encontrar alguma ocorrência do elemento.

- Se encontrar, a partir dessa posição, você deve percorrer a lista para encontrar a última ocorrência do elemento.
- Se não encontrar, o ponto de cruzamento da busca binária é a posição onde o elemento deve ser inserido.

## Entrada e Saída

- Entrada
  - 1a linha: vetor com os elementos inteiros entre colchetes separados por espaço
  - 2a linha: elemento a ser pesquisado
- Saída
  - Posição da última ocorrência do elemento ou onde ele deve ser inserido

## Testes

```bash
>>>>>>>> INSERT
[ ]
4
======== EXPECT
0
<<<<<<<< FINISH

>>>>>>>> INSERT
[ 1 1 1 ]
1
======== EXPECT
2
<<<<<<<< FINISH

>>>>>>>> INSERT
[ 1 2 3 ]
1
======== EXPECT
0
<<<<<<<< FINISH

>>>>>>>> INSERT
[ 1 2 3 ]
3
======== EXPECT
2
<<<<<<<< FINISH

>>>>>>>> INSERT
[ 1 1 1 2 2 3 ]
2
======== EXPECT
4
<<<<<<<< FINISH

>>>>>>>> INSERT
[ 1 1 1 3 3 5 ]
0
======== EXPECT
0
<<<<<<<< FINISH

>>>>>>>> INSERT
[ 1 1 1 4 4 6 6 ]
2
======== EXPECT
3
<<<<<<<< FINISH

>>>>>>>> INSERT
[ 1 1 1 4 4 6 6 ]
5
======== EXPECT
5
<<<<<<<< FINISH

>>>>>>>> INSERT
[ 1 1 1 4 4 6 6 ]
8
======== EXPECT
7
<<<<<<<< FINISH

```
