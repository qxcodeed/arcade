# Imprimindo ao contrário

![_](cover.jpg)

Dado um vetor de inteiros A, imprima um triângulo de números tal que na base do triângulo estejam todos os elementos do vetor original, e tal que, a cada i-ésimo nível acima da base, o número de elementos seja um a menos que no nível inferior e cada elemento do i-ésimo nível seja a soma de dois elementos consecutivos do nível inferior.

- Entrada
  - Os elementos da base.
- Saída
  - O triângulo.

## Dica

Veja a resolução da atividade "Empilhamento da Recursão" para entender como funciona a impressão de trás pra frente.

## Arquivos

Você deve implementar a função `processa` no arquivo `lib.cpp`.

<!-- links .cache/draft -->
- cpp
  - [main.cpp](.cache/draft/cpp/main.cpp)
- go
  - [main.go](.cache/draft/go/main.go)
- py
  - [main.py](.cache/draft/py/main.py)
<!-- links -->

## Testes

```txt

>>>>>>>> 01
1 2 3
========
[ 8 ]
[ 3 5 ]
[ 1 2 3 ]
<<<<<<<<

>>>>>>>> 02
3 2 1
========
[ 8 ]
[ 5 3 ]
[ 3 2 1 ]
<<<<<<<<

>>>>>>>> 03
4 3 2 1
========
[ 20 ]
[ 12 8 ]
[ 7 5 3 ]
[ 4 3 2 1 ]
<<<<<<<<

>>>>>>>> 04
1 1 2 3 5 8
========
[ 89 ]
[ 34 55 ]
[ 13 21 34 ]
[ 5 8 13 21 ]
[ 2 3 5 8 13 ]
[ 1 1 2 3 5 8 ]
<<<<<<<<

```
