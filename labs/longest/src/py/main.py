def longestIncreasingPath(matrix: list[list[int]]) -> int: 
    # @UNC
	# _ = matrix
	# return 0
	# @DROP
    ROWS, COLS = len(matrix), len(matrix[0])
    dp = {}

    def dfs(r: int, c: int, prevVal: int) -> int:
        if (r < 0 or r == ROWS or
            c < 0 or c == COLS or
            matrix[r][c] <= prevVal): 
            return 0

        if (r, c) in dp:
            return dp[(r, c)]

        res = 1
        res = max(res, 1 + dfs(r + 1, c, matrix[r][c])) 
        res = max(res, 1 + dfs(r - 1, c, matrix[r][c])) 
        res = max(res, 1 + dfs(r, c + 1, matrix[r][c])) 
        res = max(res, 1 + dfs(r, c - 1, matrix[r][c])) 

        dp[(r, c)] = res
        return res

    for r in range(ROWS):
        for c in range(COLS):
            dfs(r, c, -1)

    return max(dp.values())
# Não modifique a main
nl, nc = map(int, input().split())
matrix = [list(map(int, input().split())) for _ in range(nl)]
result = longestIncreasingPath(matrix)
print(result)
