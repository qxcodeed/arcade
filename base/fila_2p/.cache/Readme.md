# Fila como duas pilhas

![_](https://raw.githubusercontent.com/qxcodeed/arcade/master/base/fila_2p/../fila/cover.jpg)

## Descrição da função

Uma fila é um tipo de dados abstrato que mantém a ordem na qual os elementos foram adicionados a ela, permitindo que os elementos mais antigos sejam removidos da frente e os novos elementos sejam adicionados na parte traseira.

Isso é chamado de estrutura de dados FIFO (Primeiro a entrar, primeiro a sair), porque o primeiro elemento adicionado à fila (ou seja, aquele que está esperando há mais tempo) é sempre o primeiro a ser removido.

Nesse desafio, você deve primeiro implementar uma fila usando duas pilhas. Em seguida, processe a consultas, em que cada consulta é um dos seguintes 3 tipos:

- 1 x: Enfileirar o elemento x no final da fila.
- 2: Retirar da fila o elemento na frente da fila.
- 3: Mostre o elemento na frente da fila.

## Formato de entrada

A primeira linha contém um único número inteiro, q, denotando o número de consultas.
Cada linha i das q linhas subsequentes contém uma única consulta no padrão descrito acima no problema. Todas as três consultas começam com um número inteiro que indica o tipo da consulta, mas apenas a primeira consulta é seguida por um valor adicional x separado por espaço, indicando o valor a ser enfileirado.

## Formato de saída

Para cada consulta do tipo 3, imprima o valor do elemento na frente da fila em uma nova linha. As consultas de tipo 1 e 2 não necessitam imprimir nada.

## Ajuda

- Você pode utilizar duas pilhas.
- Vamos chamar a primeira pilha de "deposito" e a segunda de "prateleira".
- Se precisar colocar algo, você coloca no deposito.
- Se precisar pegar algo você pega da prateleira.
- Se a prateleira estiver vazia, você retira tudo do deposito para a prateleira.
  - Observe que agora o depósito foi invertido e a primeira a ser inserida no depósito é a última da prateleira.

<!-- links .cache/draft -->
<!-- links -->

## Testes

```txt
>>>>>>>>
9
1 1
1 2
1 3
3
2
3
2
3
2
========
1
2
3
<<<<<<<<

>>>>>>>> 01
10
1 42
2
1 14
3
1 28
3
1 60
1 78
2
2
========
14
14
<<<<<<<<

>>>>>>>> 02
10
1 76
1 33
2
1 23
1 97
1 21
3
3
1 74
3
========
33
33
33
<<<<<<<<

>>>>>>>> 03
100
1 92118642
2
1 107858633
1 110186788
1 883309178
1 430939631
2
1 739711408
1 803703507
1 643797161
1 538560826
3
1 595864615
1 490282285
1 558095366
1 893666727
1 595679828
3
1 99908215
3
1 333969117
1 604624143
1 88712599
1 224459820
3
1 153072902
3
3
2
1 156974087
2
1 387224973
1 154628865
1 256130200
1 704295204
2
3
1 928499989
2
3
2
1 319507446
1 323714081
1 772087837
1 350417458
1 193303587
1 213700781
3
1 565379092
1 284925173
2
1 794176274
3
1 766929345
3
2
1 42983700
2
1 156768862
1 205008057
1 93223219
3
2
1 17818922
1 917626659
1 829031126
1 346173907
1 78065001
2
3
2
3
1 565004472
1 753139390
2
1 629441479
1 935933973
1 650043630
3
1 158726470
1 206429620
3
1 590439448
1 139555053
1 78707344
1 989497950
1 880166047
2
1 137608768
3
1 861823671
1 625166323
1 431218849
3
1 570007363
2
3
3
2
1 978253366
========
110186788
110186788
110186788
110186788
110186788
110186788
739711408
803703507
643797161
538560826
538560826
490282285
893666727
595679828
99908215
99908215
333969117
333969117
604624143
604624143
<<<<<<<<
```
