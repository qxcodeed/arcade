## ©01_rec__ 2. Rec Triângulo da soma
## @qxcode

![](__capa.jpg)



Dado um vetor de inteiros A, imprima um triângulo de números
tal que na base do triângulo estejam todos os elementos do
vetor original, e tal que, a cada i-ésimo nível acima da base, o
número de elementos seja um a menos que no nível inferior e
cada elemento do i-ésimo nível seja a soma de dois elementos
consecutivos do nível inferior.

- Entrada
    - Os elementos da base
- Saída
    - O triângulo

## Testes

```

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

>>>>>>>> 05
1 2 4 8 16 32 64
========
[ 729 ]
[ 243 486 ]
[ 81 162 324 ]
[ 27 54 108 216 ]
[ 9 18 36 72 144 ]
[ 3 6 12 24 48 96 ]
[ 1 2 4 8 16 32 64 ]
<<<<<<<<


```
