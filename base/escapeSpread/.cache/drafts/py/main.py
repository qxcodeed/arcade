from collections import deque

def maximumMinutes(grid: list[list[int]]) -> int:
	# _ = grid
	# return 0
# Não modifique a main
nl, nc = map(int, input().split())
grid = [list(map(int, input().split())) for _ in range(nl)]
print(maximumMinutes(grid))
