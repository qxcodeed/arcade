# Matriz Soma e Multiplicação

## Shell

```bash
#__case new
$new 2 2
$set 0 [1,2,3,4]

$show 0
[   1,    2]
[   3,    4]

$set 0 [5,6,7,8]
$show 0
[   5,    6]
[   7,    8]

#__case new2
$new 3 5

$set 1 [1,2,3,4,5,6,-7,8,9,10,11,12,13,-12,15]
$show 1
[   1,    2,    3,    4,    5]
[   6,   -7,    8,    9,   10]
[  11,   12,   13,  -12,   15]
$end
```

```bash
#__case soma 2 2
$new 2 2
$set 0 [1,2,3,4]

$new 2 2
$set 1 [5,6,7,8]

$look
{[1, 2], [3, 4]}
{[5, 6], [7, 8]}

$sum 0 1
[   6,    8]
[  10,   12]
$end
```

```bash
#__case soma 2 2
$new 2 2
$set 0 [1,2,3,4]

$new 2 1
$set 1 [7,8]

$look
{[1, 2], [3, 4]}
{[7], [8]}

$sum 0 1
fail: incompativeis
$end
```
