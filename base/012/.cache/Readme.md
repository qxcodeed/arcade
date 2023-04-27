## @012 L2 - Matriz Soma e Multiplicação

## Guide

- [draft.cpp](https://raw.githubusercontent.com/qxcodeed/arcade/master/base/012/draft.cpp)

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
0: {[1, 2], [3, 4]}
1: {[5, 6], [7, 8]}

$sum 0 1
index: 2

$show 2
[   6,    8]
[  10,   12]

$look
0: {[1, 2], [3, 4]}
1: {[5, 6], [7, 8]}
2: {[6, 8], [10, 12]}

$end
```

```bash
#__case soma incompativel
$new 2 2
$set 0 [1,2,3,4]

$new 2 1
$set 1 [7,8]

$look
0: {[1, 2], [3, 4]}
1: {[7], [8]}

$sum 0 1
fail: incompativeis

$end
```

```bash
#__case mult
$new 1 4
$set 0 [1,2,3,4]

$new 4 1
$set 1 [1,2,3,4]

$look
0: {[1, 2, 3, 4]}
1: {[1], [2], [3], [4]}

#__case incompativel
$sum 0 1
fail: incompativeis

#__case mult 1 4 * 4 1
$prod 0 1
index: 2

$look
0: {[1, 2, 3, 4]}
1: {[1], [2], [3], [4]}
2: {[30]}

$end
```

```bash
#__case mult
$new 2 4
$set 0 [1,2,3,4,5,6,7,8]

$new 4 1
$set 1 [10,20,30,40]

$look
0: {[1, 2, 3, 4], [5, 6, 7, 8]}
1: {[10], [20], [30], [40]}

#__case mult 2 4 x 4 1

$prod 0 1
index: 2

$look
0: {[1, 2, 3, 4], [5, 6, 7, 8]}
1: {[10], [20], [30], [40]}
2: {[300], [700]}

$end
```
