# Lista Dupla - Extra

<!-- toch -->
[Intro](#intro) | [Shell](#shell)
-- | --
<!-- toch -->

## Intro

Utilizando a estrutura criada em @lista_d2, vamos fazer algumas manipulações de dados.

## Shell

```bash
#TEST_CASE compare <lista1> <lista2>
# compara se duas listas são iguais
$compare [1,2,3,4,5] [1,2,3,4,5]
iguais
$compare [] []
iguais
$compare [1] [2]
diferentes
$compare [1,2] [1]
diferentes
$compare [1] [1,2]
diferentes
$compare [1,2] [1,3]
diferentes
$compare [2,1] [1,2]
diferentes
$compare [1,3,2] [1,3,2]
iguais
$end
```

```bash
#TEST_CASE addsorted
# insere os valores de forma ordenada dentro da estrutura
$addsorted 4 5 7 4 2 8 1 9 0
[0, 1, 2, 4, 4, 5, 7, 8, 9]
$end
```

```bash
#TEST_CASE reverse
$reverse []
[]
$reverse [1]
[1]
$reverse [1,2]
[2, 1]
$reverse [1,2,3,4,5,6,7,8]
[8, 7, 6, 5, 4, 3, 2, 1]
$end
```

```bash
#TEST_CASE merge
# faça o merge de duas listas ordenadas, inserindo a segunda lista na primeira
# aproveitando a ideia de que ambas estão ordenadas
$merge [1,5,6,8] [2,3,3,4,4,9]
[1, 2, 3, 3, 4, 4, 5, 6, 8, 9]
$merge [1] [2]
[1, 2]
$merge [2] [1]
[1, 2]
$merge [2,3] [1,2]
[1, 2, 2, 3]
$merge [2,3] [1,4,5]
[1, 2, 3, 4, 5]
$end
```
