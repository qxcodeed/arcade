# Implemente o mdc recursivo

Implemente a função que calcula o mdc de dois números de forma recursiva.

O mdc de dois números inteiros é o maior número inteiro que divide ambos sem deixar resto.
Para calcular o mdc de dois números, você pode usar o algoritmo de Euclides.

[LINK](https://pt.khanacademy.org/computing/computer-science/cryptography/modarithmetic/a/the-euclidean-algorithm)

## O Algoritmo

- O Algoritmo Euclidiano para encontrar o MDC(A,B) é dado por:

- Se A = 0, então MDC(A,B)=B, uma vez que MDC(0,B)=B, e podemos parar a verificação.  
- Se B = 0, então MDC(A,B)=A, uma vez que o MDC(A,0)=A, e podemos parar a verificação.  
- Escreva A na forma do resto do quociente (A = B⋅Q + R), ou seja R = A % B.
- Encontre o MDC(B,R) usando o Algoritmo Euclidiano, já que MDC(A,B) = MDC(B,R)

## I/O

- Entrada
  - A entrada consiste de dois números inteiros positivos.
- Saída
  - A saída consiste de um número inteiro positivo que representa o mdc dos dois números.
  
## Exemplos

<!-- load tests.toml --tests 3 -->
```py
>>>>>>>> INSERT
3
5
======== EXPECT
1
<<<<<<<< FINISH
```

```py
>>>>>>>> INSERT
6
9
======== EXPECT
3
<<<<<<<< FINISH
```

```py
>>>>>>>> INSERT
50
15
======== EXPECT
5
<<<<<<<< FINISH
```
<!-- load -->
