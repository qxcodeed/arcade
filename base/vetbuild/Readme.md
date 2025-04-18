# Implementando lista sequencial dinâmica

![_](cover.jpg)

Implemente as seguintes funções do vetor dinâmico.

```bash
#__case create
$init 3
$status
size:0 capacity:3
$show
[]
$end
```

```bash
#__case push
$init 1
$status
size:0 capacity:1
$show
[]
$push 3
$show
[3]
$status
size:1 capacity:1
$push 4
$show
[3, 4]
$status
size:2 capacity:2
$push 5
$show
[3, 4, 5]
$status
size:3 capacity:4
$push 1
$show
[3, 4, 5, 1]
$status
size:4 capacity:4
$push 2
$show
[3, 4, 5, 1, 2]
$status
size:5 capacity:8
$end
```

```bash
#__case get e set
$init 10
$push 10 2 8 12 8 6
$show
[10, 2, 8, 12, 8, 6]
$get 2
8
$set 2 20
$show
[10, 2, 20, 12, 8, 6]
$get 10
index out of range
$set 10 20
index out of range
$show
[10, 2, 20, 12, 8, 6]
$end
```

```bash
#__case clear
$init 6
$push 1 2 3 4 5 6
$clear
$show
[]
$status
size:0 capacity:6
$end
```

```bash
#__case reserve
$init 6
$push 1 2 3 4 5 6
$show
[1, 2, 3, 4, 5, 6]
$reserve 10
$show
[1, 2, 3, 4, 5, 6]
$status
size:6 capacity:10
$end
```

```bash
#__case pop
$init 5
$push 1 2 3 4 5
$show
[1, 2, 3, 4, 5]
$pop
$show
[1, 2, 3, 4]
$pop
$pop
$pop
$show
[1]
$status
size:1 capacity:5
$pop
$show
[]
$pop
vector is empty
$status
size:0 capacity:5
$end
```

```bash
#__case insert
$init 6
$push 1 2 3 4 5
$insert 2 10
$show
[1, 2, 10, 3, 4, 5]
$status
size:6 capacity:6
$insert 0 20
$show
[20, 1, 2, 10, 3, 4, 5]
$status
size:7 capacity:12
$end
```

```bash
#__case insert_resize
$init 6
$push 1 2 3 4 5 6
$insert 2 10
$show
[1, 2, 10, 3, 4, 5, 6]
$status
size:7 capacity:12
$end
```

```bash
#__case erase
$init 6
$push 1 2 3 4 5 6
$show
[1, 2, 3, 4, 5, 6]
$erase 2
$show
[1, 2, 4, 5, 6]
$status
size:5 capacity:6
$erase 0
$show
[2, 4, 5, 6]
$status
size:4 capacity:6
$erase 8
index out of range
$status
size:4 capacity:6
$show
[2, 4, 5, 6]
$end
```

```bash
#__case indexOf e contains
$init 10
$push 10 2 8 12 8 6
$indexOf 12
3
$indexOf 8
2
$indexOf 7
-1
$contains 12
true
$end
```

```bash
#__case reverse e sort
$init 10
$push 10 2 8 12 8 6
$show
[10, 2, 8, 12, 8, 6]
$reverse
$show
[6, 8, 12, 8, 2, 10]
$sort
$show
[2, 6, 8, 8, 10, 12]
$end
```

```bash
#__case sorted
$init 10
$push 10 2 8 12 8 6
$show
[10, 2, 8, 12, 8, 6]
$sorted
[2, 6, 8, 8, 10, 12]
$show
[10, 2, 8, 12, 8, 6]
$end
```
