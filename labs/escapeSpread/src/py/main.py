from collections import deque

def maximumMinutes(grid: list[list[int]]) -> int:
    # @UNC
	# _ = grid
	# return 0
	# @DROP
    ROWS, COLS = len(grid), len(grid[0])
    fire_time = [[float('inf')] * COLS for _ in range(ROWS)]
    q = deque()

    for r in range(ROWS):
        for c in range(COLS):
            if grid[r][c] == 1:
                fire_time[r][c] = 0
                q.append((r, c, 0))
    
    directions = [(1,0), (-1,0), (0,1), (0,-1)]
    while q:
        r, c, t = q.popleft()
        for dr, dc in directions:
            nr, nc = r + dr, c + dc
            if 0 <= nr < ROWS and 0 <= nc < COLS and grid[nr][nc] == 0 and fire_time[nr][nc] == float('inf'):
                fire_time[nr][nc] = t + 1
                q.append((nr, nc, t + 1))

    def can_escape(wait: int) -> bool:
        if fire_time[0][0] <= wait:
            return False
        vis = [[False]*COLS for _ in range(ROWS)]
        q = deque([(0, 0, wait)])
        vis[0][0] = True
        while q:
            r, c, t = q.popleft()
            if r == ROWS-1 and c == COLS-1:
                return True
            for dr, dc in directions:
                nr, nc = r + dr, c + dc
                nt = t + 1
                if 0 <= nr < ROWS and 0 <= nc < COLS and grid[nr][nc] != 2 and not vis[nr][nc] and nt < fire_time[nr][nc]:
                    vis[nr][nc] = True
                    q.append((nr, nc, nt))
        return False

    low, high = 0, ROWS*COLS
    ans = -1
    while low <= high:
        mid = (low + high)//2
        if can_escape(mid):
            ans = mid
            low = mid + 1
        else:
            high = mid - 1

    return 10**9 if ans >= ROWS*COLS else ans

# Não modifique a main
nl, nc = map(int, input().split())
grid = [list(map(int, input().split())) for _ in range(nl)]
print(maximumMinutes(grid))
