from typing import List

class Solution:
    
    directions=[(0,1),(0,-1),(1,0),(-1,0)]
    
    def is_valid(self,i,j,n):
        return i>=0 and i<n and j>=0 and j<n
    
    def dfs_mod(self,grid,i,j,visited,name):
        grid[i][j]=name
        n=len(grid)
        visited[i][j]=True
        count=1
        for dx,dy in self.directions:
            new_i,new_j=i+dx,j+dy
            if self.is_valid(new_i,new_j,n) and grid[new_i][new_j]==1 and not visited[new_i][new_j]:
                count+=self.dfs_mod(grid,new_i,new_j,visited,name)
        return count
    
    def largestIsland(self, grid : List[List[int]]) -> int:
        n=len(grid)
        visited=[[False]*n for _ in range(n)]
        name=2
        size_of=dict()
        for i in range(n):
            for j in range(n):
                if grid[i][j]==1 and not visited[i][j]:
                    count=self.dfs_mod(grid,i,j,visited,name)
                    size_of[name]=count
                    name+=1
        ans=0
        for i in range(n):
            for j in range(n):
                if grid[i][j]==0:
                    count=1
                    s=set()
                    for dx,dy in self.directions:
                        new_i,new_j=i+dx,j+dy
                        if self.is_valid(new_i,new_j,n) and grid[new_i][new_j]!=0:
                            s.add(grid[new_i][new_j])
                    for name in s:
                        count+=size_of[name]
                    ans=max(ans,count)
        return ans if ans!=0 else n*n
        # Code here





#{ 
 # Driver Code Starts

class IntMatrix:
    def __init__(self) -> None:
        pass
    def Input(self,n,m):
        matrix=[]
        #matrix input
        for _ in range(n):
            matrix.append([int(i) for i in input().strip().split()])
        return matrix
    def Print(self,arr):
        for i in arr:
            for j in i:
                print(j,end=" ")
            print()

if __name__=="__main__":
    t = int(input())
    for _ in range(t):
        
        n = int(input())
        
        
        grid=IntMatrix().Input(n,n)
        
        obj = Solution()
        res = obj.largestIsland(grid)
        
        print(res)
# } Driver Code Ends