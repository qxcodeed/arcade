# Apagando elementos de forma eficiente

![_](assets/cover.jpg)

Com a proximidade da Copa do Mundo, o fluxo de pessoas nas filas para compra de ingressos aumentou consideravelmente. Como as filas estão cada vez maiores, pessoas menos pacientes tendem a desistir da compra de ingressos e acabam deixando as filas, liberando assim vaga para outras pessoas. Quando uma pessoa deixa a fila, todas as pessoas que estavam atrás dela dão um passo a frente, sendo assim nunca existe um espaço vago entre duas pessoas. A fila inicialmente contém N pessoas, cada uma com um identificador diferente.

Joãozinho sabe o estado inicial dela e os identificadores em ordem das pessoas que deixaram a fila. Sabendo que após o estado inicial nenhuma pessoa entrou mais na fila, Joãozinho deseja saber o estado final da fila.

## Entrada

- A primeira linha contém um inteiro **N** representando a quantidade de pessoas inicialmente na fila.
- A segunda linha contém **N** inteiros representando os identificadores das pessoas na fila. O primeiro identificador corresponde ao identificador da primeira pessoa na fila. É garantido que duas pessoas diferentes não possuem o mesmo identificador.
- A terceira linha contém um inteiro **M** representando a quantidade de pessoas que deixaram a fila.
- A quarta linha contém M inteiros representando os identificadores das pessoas que deixaram a fila, na ordem em que elas saíram. É garantido que um mesmo identificador não aparece duas vezes nessa lista.

## Saída

Seu programa deve imprimir uma linha contedo **N-M** inteiros com os identificadores das pessoas que permaneceram na fila, em ordem de chegada.

## Dicas

- Armazene os elementos a serem removidos em um conjunto ou mapa. Dessa forma, consultar o elementos pode ser feito de forma eficiente.
- Ao invés de remover do vetor original, que é uma operação ineficiente, percorra o vetor original consultando se o elemento deve permanecer e preencha um novo vetor.
- Assim, o custo total permanece O(N)

## Exemplos

<!-- load tests.toml --tests 3 -->
```py
>>>>>>>> INSERT
10
817 364 524 565 132 499 412 563 297 638 
7
364 817 412 132 499 524 297 
======== EXPECT
565 563 638 
<<<<<<<< FINISH
```

```py
>>>>>>>> INSERT
9
2 840 316 408 711 537 296 565 735 
5
316 565 408 735 2 
======== EXPECT
840 711 537 296 
<<<<<<<< FINISH
```

```py
>>>>>>>> INSERT
7
831 565 110 581 726 770 990 
3
770 581 565 
======== EXPECT
831 110 726 990 
<<<<<<<< FINISH
```
<!-- load -->
