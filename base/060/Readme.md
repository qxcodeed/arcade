## Rotação à direira em array ©array

A left rotation operation on an array of size _**n**_ shifts each of the array's elements unit to the left. For example, if left rotations are performed on array _**[1,2,3,4,5]**_, then the array would become

.

<img src="https://render.githubusercontent.com/render/math?math=1 \leq n \leq 10^5">

Given an array of
integers and a number, , perform

left rotations on the array. Then print the updated array as a single line of space-separated integers.

Input Format

The first line contains two space-separated integers denoting the respective values of
(the number of integers) and (the number of left rotations you must perform).
The second line contains

space-separated integers describing the respective elements of the array's initial state.

Constraints

Output Format

Print a single line of
space-separated integers denoting the final state of the array after performing

left rotations.

Sample Input

5 4
1 2 3 4 5

Sample Output

5 1 2 3 4

Explanation

When we perform

left rotations, the array undergoes the following sequence of changes:

Thus, we print the array's final state as a single line of space-separated values, which is 5 1 2 3 4.

```
>>>>>>>>
5 0
1 2 3 4 5
========
[ 1 2 3 4 5 ]
<<<<<<<<

>>>>>>>>
5 1
1 2 3 4 5
========
[ 5 1 2 3 4 ]
<<<<<<<<

>>>>>>>>
5 4
1 2 3 4 5
========
[ 2 3 4 5 1 ]
<<<<<<<<

>>>>>>>>
5 9
1 2 3 4 5
========
[ 2 3 4 5 1 ]
<<<<<<<<




```