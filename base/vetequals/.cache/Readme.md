# Verifique se dois vetores são iguais recursivamente

Este documento descreve um método para verificar se dois vetores são iguais de forma recursiva.

Você não deve usar laço, nem len ou size para verificar o tamanho dos vetores.

## Entrada

- 1a linha: valores do primeiro vetor separados por espaço entre colchetes
- 2a linha: valores do segundo vetor separados por espaço entre colchetes

## Saída

- "iguais" se os vetores forem iguais
- "diferentes" se os vetores forem diferentes

## Testes

```txt

>>>>>>>>
[ ]
[ ]
========
iguais
<<<<<<<<
```

```txt
>>>>>>>>
[ 1 ]
[ 1 ]
========
iguais
<<<<<<<<
```

```txt
>>>>>>>>
[ 1 ]
[ 1 2 ]
========
diferentes
<<<<<<<<

>>>>>>>>
[ 1 2 ]
[ 1 ]
========
diferentes
<<<<<<<<

>>>>>>>>
[ 2 1 ]
[ 1 ]
========
diferentes
<<<<<<<<

>>>>>>>>
[ 1 ]
[ 2 1 ]
========
diferentes
<<<<<<<<

>>>>>>>>
[ 1 3 ]
[ 2 1 ]
========
diferentes
<<<<<<<<

>>>>>>>>
[ 3 1 ]
[ 2 1 ]
========
diferentes
<<<<<<<<

>>>>>>>>
[ 1 2 3 ]
[ 1 2 3 ]
========
iguais
<<<<<<<<

>>>>>>>>
[ 1 2 3 4 ]
[ 1 2 3 ]
========
diferentes
<<<<<<<<
```
