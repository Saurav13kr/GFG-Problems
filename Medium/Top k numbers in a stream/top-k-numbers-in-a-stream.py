#User function Template for python3

class Solution:
      def kTop(self,a, N, K):
        ans=[]
        res=[]
        visited={}
        for i in a:
            if i in visited:
                ans[visited[i]-1].remove(i)
                visited[i]+=1
                if len(ans)>=visited[i]:
                    ans[visited[i]-1].append(i)
                    ans[visited[i]-1].sort()
                else:
                    ans.append([i])
            else:
                visited[i]=1
                if len(ans)==0:
                    ans=[[i]]
                else:
                    ans[0].append(i)
                    ans[0].sort()
                    
            r=[]
            for x in range(len(ans)-1,-1,-1):
                for y in range(len(ans[x])):
                    r.append(ans[x][y])
                    if len(r)==K:
                        break
                if len(r)==K:
                    break
            res.append(r)
        return res

#{ 
 # Driver Code Starts


t=int(input())
for _ in range(0,t):
    n,k=list(map(int,input().split()))
    a=list(map(int,input().split()))
    ob = Solution()
    ans=ob.kTop(a,n,k)
    for line in ans:
        print(*line)



# } Driver Code Ends