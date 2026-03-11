def longestIncreasingPath(matrix: list[list[int]]) -> int: 
	# _ = matrix
	# return 0
# Não modifique a main
nl, nc = map(int, input().split())
matrix = [list(map(int, input().split())) for _ in range(nl)]
result = longestIncreasingPath(matrix)
print(result)
