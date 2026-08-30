from typing import List

def countBattleships(board: List[List[str]]) -> int:
	# @UNC
	# _ = board
	# return 0
	# @DROP
    nrows = len(board)
    ncols = len(board[0])
    if nrows == 0:
        return 0

    counter = 0

    def dfs(r, c):
        if r < 0 or r >= nrows or c < 0 or c >= ncols or board[r][c] != 'X':
            return
        board[r][c] = 'V'
        dfs(r+1, c)
        dfs(r-1, c)
        dfs(r, c+1)
        dfs(r, c-1)

    for i in range(nrows):
        for j in range(ncols):
            if board[i][j] == 'X':
                counter += 1
                dfs(i, j)
    return counter

# Não modifique a main
nl, nc = map(int, input().split())
board = [list(input().strip()) for _ in range(nl)]
result = countBattleships(board)
print(result)
