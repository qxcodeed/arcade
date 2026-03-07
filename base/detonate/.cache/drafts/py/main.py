from math import sqrt
from collections import defaultdict

def maximumDetonation(bombs: list[list[int]]) -> int:
	# _ = bombs
	# return 0
# Não modifique a main
n, _ = map(int, input().split())
bombs = [list(map(int, input().split())) for _ in range(n)]
print(maximumDetonation(bombs))
