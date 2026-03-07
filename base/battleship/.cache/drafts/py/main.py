from typing import List

def countBattleships(board: List[List[str]]) -> int:
	# _ = board
	# return 0
# Não modifique a main
nl, nc = map(int, input().split())
board = [list(input().strip()) for _ in range(nl)]
result = countBattleships(board)
print(result)
