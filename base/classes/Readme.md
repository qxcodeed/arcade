# Implementando vector com @classes

![_](cover.jpg)

Implemente as seguintes funções do vetor dinâmico.

- Ele deve ser iniciado utilizando alocação dinâmica e conter além do vetor de dados, `size` e `capacity` que definem o tamanho atual e a capacidade do vetor.

```bash
#__case create
$init 3
$show
size:0 capacity:3
[]
$end
```

```bash
#__case add
$show
size:0 capacity:1
[]
$push_back 3
$show
size:0 capacity:1
[3]
$push_back 4
$show
size:2 capacity:2
[3, 4]
$push_back 5
$show
size:3 capacity:4
[3, 4, 5]
$push_back 1
$show
size:4 capacity:4
[3, 4, 5, 1]
$push_back 2
$show
size:5 capacity:8
[3, 4, 5, 1, 2]
$end
```
