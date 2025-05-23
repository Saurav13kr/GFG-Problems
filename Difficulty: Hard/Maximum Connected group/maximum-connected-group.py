from typing import List


class Solution:
    def MaxConnection(self, grid : List[List[int]]) -> int:
        n = len(grid)
        
        def dfs(x, y, visited):
            stack = [(x, y)]
            visited.add((x, y))
            size = 0
            component = [(x, y)]
            while stack:
                cx, cy = stack.pop()
                size += 1
                for dx, dy in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
                    nx, ny = cx + dx, cy + dy
                    
                    if 0 <= nx < n and 0 <= ny < n and grid[nx][ny] == 1 and (nx, ny) not in visited:
                        visited.add((nx, ny))
                        stack.append((nx, ny))
                        component.append((nx, ny))
            return size,
            component
    
        visited = set()
        group_sizes = {}
        index_grid = [[-1] * n for _ in range(n)]
        group_index = 0
    
        for i in range(n):
            for j in range(n):
                if grid[i][j] == 1 and (i, j) not in visited:
                    size, component = dfs(i, j, visited)
                    group_sizes[group_index] = size
                    
                    for x, y in component:
                        index_grid[x][y] = group_index
                    group_index += 1
    
        max_size = max(group_sizes.values(), default=0)
    
        for i in range(n):
            for j in range(n):
                if grid[i][j] == 0:
                    seen = set()
                    new_size = 1
                    for dx, dy in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
                        ni, nj = i + dx, j + dy
                        if 0 <= ni < n and 0 <= nj < n and grid[ni][nj] == 1:
                            group_id = index_grid[ni][nj]
                            if group_id not in seen:
                                new_size += group_sizes[group_id]
                                seen.add(group_id)
                    max_size = max(max_size, new_size)
    
        return max_size

#{ 
 # Driver Code Starts
class IntMatrix:

    def __init__(self) -> None:
        pass

    def Input(self, n, m):
        matrix = []
        #matrix input
        for _ in range(n):
            matrix.append([int(i) 
                           for i in input().strip().split()])
        return matrix

    def Print(self, arr):
        for i in arr:
            for j in i:
                print(j, end=" ")
            print()


if __name__ == "__main__":
    t = int(input())
    for _ in range(t):

        n = int(input())

        grid = IntMatrix().Input(n, n)

        obj = Solution()
        res = obj.MaxConnection(grid)

        print(res)

# } Driver Code Ends
