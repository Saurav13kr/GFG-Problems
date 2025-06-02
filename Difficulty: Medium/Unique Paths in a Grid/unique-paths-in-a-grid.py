class Solution:
    
    def findPaths(self,i,j,grid,n,m,dp):
        if i>=n or j>=m : return 0
        if i==n-1 and j==m-1 : return 1
        if dp[i][j] != -1 : return dp[i][j]
        right , bottom = 0 , 0
        if j+1<m:
            if grid[i][j] != 1:
              right = self.findPaths(i,j+1,grid,n,m,dp)
        if i+1<n:
            if grid[i][j] != 1:
              bottom = self.findPaths(i+1,j,grid,n,m,dp)
        
        dp[i][j] = right+bottom
        return dp[i][j]
    
    def uniquePaths(self, grid):
        if grid[0][0] == 1 :
            return 0
        dp = [[-1 for _ in range(len(grid[0]))] for _ in range(len(grid))]
        paths = self.findPaths(0,0,grid,len(grid),len(grid[0]),dp)
        return paths