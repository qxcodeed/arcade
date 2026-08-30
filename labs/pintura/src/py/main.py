from typing import List

def floodFill(image: List[List[int]], sr: int, sc: int, color: int) -> List[List[int]]:
	#
    # @UNC
	# _ = image
	# return _
	# @DROP
    nrows = len(image)
    ncols = len(image[0])
    if nrows == 0:
        return image

    oc = image[sr][sc]
    if oc == color:
        return image

    def dfs(r, c):
        if r < 0 or r >= nrows or c < 0 or c >= ncols or image[r][c] != oc:
            return
        image[r][c] = color
        dfs(r+1, c)
        dfs(r-1, c)
        dfs(r, c+1)
        dfs(r, c-1)

    dfs(sr, sc)
    return image

# Não modifique a main
nl, nc = map(int, input().split())
image = [list(map(int, input().split())) for _ in range(nl)]
sr, sc, color = map(int, input().split())
result = floodFill(image, sr, sc, color)
for row in result:
    print(" ".join(map(str, row)))
