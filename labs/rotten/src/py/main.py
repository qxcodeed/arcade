from collections import deque

def orangesRotting(grid: list[list[int]]) -> int:
    # @UNC
	# _ = grid
	# return 0
	# @DROP
    rows, cols = len(grid), len(grid[0])
    q = deque()
    fresh = 0

    for r in range(rows):
        for c in range(cols):
            if grid[r][c] == 2:
                q.append((r, c, 0))
            elif grid[r][c] == 1:
                fresh += 1

    minutes = 0
    directions = [(1,0), (-1,0), (0,1), (0,-1)]

    while q:
        r, c, t = q.popleft()
        minutes = max(minutes, t)

        for dr, dc in directions:
            nr, nc = r + dr, c + dc
            if 0 <= nr < rows and 0 <= nc < cols and grid[nr][nc] == 1:
                grid[nr][nc] = 2
                fresh -= 1
                q.append((nr, nc, t + 1))

    return minutes if fresh == 0 else -1


# Não modifique a main
nl, nc = map(int, input().split())
grid = [list(map(int, input().split())) for _ in range(nl)]
print(orangesRotting(grid))
