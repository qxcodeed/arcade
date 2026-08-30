# Aragão calculando n ao quadrado

Aragão está profundamente envolvido em seu aprendizado sobre recursão. Recentemente, ele fez uma descoberta fascinante: o cálculo de $n^2$ pode ser expresso de maneira recursiva por meio da seguinte fórmula iterativa: $(n+1)^2 = n^2 + 2n + 1$, começando com $1^2 = 1$ como caso base.

Empolgado com essa revelação, Aragão deseja desenvolver um algoritmo recursivo que não apenas calcule $n^2$, mas também mostre cada passo do processo. No entanto, ele enfrenta algumas dificuldades para elaborar tal algoritmo. É aí que entra a sua ajuda.

## Entrada

A entrada é composta por uma única linha contendo um inteiro $n$

## Saída

A saída é composta por várias linhas mostrando o passo-a-passo do algoritmo recursivo.

## Exemplos

<!-- load tests.toml --tests 3 -->
```py
>>>>>>>> INSERT
1
======== EXPECT
1^2 = 1
<<<<<<<< FINISH
```

```py
>>>>>>>> INSERT
2
======== EXPECT
2^2 = 1^2 + 2*1 + 1 = ?
1^2 = 1
2^2 = 1^2 + 2*1 + 1 = 4
<<<<<<<< FINISH
```

```py
>>>>>>>> INSERT
3
======== EXPECT
3^2 = 2^2 + 2*2 + 1 = ?
2^2 = 1^2 + 2*1 + 1 = ?
1^2 = 1
2^2 = 1^2 + 2*1 + 1 = 4
3^2 = 2^2 + 2*2 + 1 = 9
<<<<<<<< FINISH
```
<!-- load -->
