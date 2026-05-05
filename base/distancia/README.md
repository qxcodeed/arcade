# Colocando os números no lugar certo

![_](assets/cover.jpg)

- Seja uma string formada por dígitos e underlines `.`.
- Seja um valor de limite L.

Objetivos:

- Você deve substituir todos os `.` por dígitos seguindo as seguintes regras.
  - Só pode utilizar dígitos de 0 até L, incluindo L.
  - Qualquer dígito precisa estar a uma distância mínima de L casas de outra ocorrência dele mesmo, tanto à esquerda como à direita.

- Para cada problema, existe uma e somente uma solução.

## Entrada e Saída

- Entrada
  - 1a linha: sequência.
  - 2a linha: valor de L.
- Saída
  - A string solução do problema.

## Limites

- sequência de tamanho t, 0 > t > 100
- 0 > L > 100

___

## Exemplos

<!-- load tests.toml --tests 3 -->
```py
>>>>>>>> INSERT
01.2.
3
======== EXPECT
01320
<<<<<<<< FINISH
```

```py
>>>>>>>> INSERT
.0..231..5
5
======== EXPECT
1045231045
<<<<<<<< FINISH
```

```py
>>>>>>>> INSERT
2..0..............3...........
3
======== EXPECT
213021302130213021302130213021
<<<<<<<< FINISH
```
<!-- load -->
