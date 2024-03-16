# L2 - @princesa v1

- Veja a versão online: [aqui.](https://github.com/qxcodeed/arcade/blob/master/base/princesa/Readme.md)
- Para programar na sua máquina (local/virtual) use:
  - `tko down ed princesa`
- Se não tem o `tko`, instale pelo [LINK](https://github.com/senapk/tko#tko).

---

[![_](https://raw.githubusercontent.com/qxcodeed/arcade/master/base/princesa/cover.jpg)](https://www.youtube.com/watch?v=uCsD3ZGzMgE)

[](solver.cpp)
Um problema bem interessante e antigo da matemática é conhecido como Josephus Problem. No link da imagem você pode, por curiosidades aprender bastantes sobre ele e o modelo matemático que se propõe a modelá-lo.

Nosso objetivo aqui será apenas implementar seu funcionamento.

___

No problema, **N** pessoas se colocam numa fila circular e assumem valores de 1 até **N**. Um número **E** é escolhido para iniciar o jogo. **E** pega a espada, mata o elemento à sua frente e passa a espada uma posição à frente. O jogo continua até que um único elemento permaneça vivo.

___

- Entrada:
  - Os valores de **N** e **E** na primeira linha.
- Saída:
  - Etapa a etapa, os elementos que estão vivos na fila circular, indicando com um > quem está com a espada.

___

## Implementação usando vetor

### Abordagem I

- marcando os elementos que morrem.
  - toda vez que alguém morrer, marque 0 no vetor
  - procure pelo próximo elemento vivo a direita

```c
int elementos[size];
//matar equivale a fazer
vivos[pos] = false;
//o próximo vivo seria uma busca pelo próximo vivo depois de pos
int prox = procurar_vivo(elementos, size, pos);
```

### Abordagem II

- retirando os elementos que morrem e diminuindo o tamanho do vetor.
  - reposicione os elementos "puxando" todos os que estiverem à frente

```c
//faça a funcao matar que remove o elemento do vetor
//perceba que TUDO após pos, vai diminuir em 1
int elementos[size];
matar(elementos, size, pos);
size -= 1;
pos = pos % size; //se ele era o último agora é o zero
```

### Comparação

- Qual dos algoritmos você acha que é mais eficiente?
- Implemente os dois e vá aumentando a instância do problema e veja o resultado.

___

## Implementação usando listas

Resolva novamente o problema utilizando uma lista ligada no lugar do vetor.

```c
struct Node{
    int value;
    Node * next;
};

```

___
Testes:

```txt
>>>>>>>> 01
3 1
========
[ 1> 2 3 ]
[ 1 3> ]
[ 3> ]
<<<<<<<<

>>>>>>>> 02
3 2
========
[ 1 2> 3 ]
[ 1> 2 ]
[ 1> ]
<<<<<<<<

>>>>>>>> 03
3 3
========
[ 1 2 3> ]
[ 2> 3 ]
[ 2> ]
<<<<<<<<

>>>>>>>> 04
6 3
========
[ 1 2 3> 4 5 6 ]
[ 1 2 3 5> 6 ]
[ 1> 2 3 5 ]
[ 1 3> 5 ]
[ 1> 3 ]
[ 1> ]
<<<<<<<<

>>>>>>>> 05
9 9
========
[ 1 2 3 4 5 6 7 8 9> ]
[ 2> 3 4 5 6 7 8 9 ]
[ 2 4> 5 6 7 8 9 ]
[ 2 4 6> 7 8 9 ]
[ 2 4 6 8> 9 ]
[ 2> 4 6 8 ]
[ 2 6> 8 ]
[ 2> 6 ]
[ 2> ]
<<<<<<<<

>>>>>>>> 06
20 1
========
[ 1> 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 ]
[ 1 3> 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 ]
[ 1 3 5> 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 ]
[ 1 3 5 7> 8 9 10 11 12 13 14 15 16 17 18 19 20 ]
[ 1 3 5 7 9> 10 11 12 13 14 15 16 17 18 19 20 ]
[ 1 3 5 7 9 11> 12 13 14 15 16 17 18 19 20 ]
[ 1 3 5 7 9 11 13> 14 15 16 17 18 19 20 ]
[ 1 3 5 7 9 11 13 15> 16 17 18 19 20 ]
[ 1 3 5 7 9 11 13 15 17> 18 19 20 ]
[ 1 3 5 7 9 11 13 15 17 19> 20 ]
[ 1> 3 5 7 9 11 13 15 17 19 ]
[ 1 5> 7 9 11 13 15 17 19 ]
[ 1 5 9> 11 13 15 17 19 ]
[ 1 5 9 13> 15 17 19 ]
[ 1 5 9 13 17> 19 ]
[ 1> 5 9 13 17 ]
[ 1 9> 13 17 ]
[ 1 9 17> ]
[ 9> 17 ]
[ 9> ]
<<<<<<<<


```
