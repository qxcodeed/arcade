# Imprimindo ao contrário

![_](assets/cover.jpg)

Dado um vetor de inteiros A, imprima um triângulo de números tal que na base do triângulo estejam todos os elementos do vetor original, e tal que, a cada i-ésimo nível acima da base, o número de elementos seja um a menos que no nível inferior e cada elemento do i-ésimo nível seja a soma de dois elementos consecutivos do nível inferior.

- Entrada
  - Os elementos da base.
- Saída
  - O triângulo.

## Dica

Veja a resolução da atividade "Empilhamento da Recursão" para entender como funciona a impressão de trás pra frente.

## Exemplos

<!-- load tests.toml --tests 3 -->
```py
>>>>>>>> INSERT
1 2 4 8 16 32 64
======== EXPECT
[ 729 ]
[ 243 486 ]
[ 81 162 324 ]
[ 27 54 108 216 ]
[ 9 18 36 72 144 ]
[ 3 6 12 24 48 96 ]
[ 1 2 4 8 16 32 64 ]
<<<<<<<< FINISH
```
<!-- load -->
