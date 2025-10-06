class Solution:
    def knightTour(self, n):
        board = [[-1 for _ in range(n)] for _ in range(n)]
        
        moves = [(2, 1), (1, 2), (-1, 2), (-2, 1),
                 (-2, -1), (-1, -2), (1, -2), (2, -1)]
        def is_safe(x, y):
            return 0 <= x < n and 0 <= y < n and board[x][y] == -1
        
        def solve(x, y, step):
            board[x][y] = step
            if step == n*n - 1:
                return True  
            
            for dx, dy in moves:
                nx, ny = x + dx, y + dy
                if is_safe(nx, ny):
                    if solve(nx, ny, step + 1):
                        return True
            
            board[x][y] = -1 
            return False
        
        if solve(0, 0, 0):
            return board
        else:
            return [[-1]]