from math import sqrt
from collections import defaultdict

def maximumDetonation(bombs: list[list[int]]) -> int:
    # @UNC
	# _ = bombs
	# return 0
	# @DROP
    n = len(bombs)
    adj = defaultdict(list)

    for i in range(n):
        x1, y1, r1 = bombs[i]
        for j in range(i + 1, n):
            x2, y2, r2 = bombs[j]
            d = sqrt((x1 - x2)**2 + (y1 - y2)**2)
            if d <= r1:
                adj[i].append(j)
            if d <= r2:
                adj[j].append(i)

    def dfs(i: int, visit: set[int]) -> int:
        if i in visit:
            return 0
        visit.add(i)
        for nei in adj[i]:
            dfs(nei, visit)
        return len(visit)

    res = 0
    for i in range(n):
        res = max(res, dfs(i, set()))
    return res

# Não modifique a main
n, _ = map(int, input().split())
bombs = [list(map(int, input().split())) for _ in range(n)]
print(maximumDetonation(bombs))
