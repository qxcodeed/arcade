from typing import List

def floodFill(image: List[List[int]], sr: int, sc: int, color: int) -> List[List[int]]:
	#
	# _ = image
	# return _
# Não modifique a main
nl, nc = map(int, input().split())
image = [list(map(int, input().split())) for _ in range(nl)]
sr, sc, color = map(int, input().split())
result = floodFill(image, sr, sc, color)
for row in result:
    print(" ".join(map(str, row)))
