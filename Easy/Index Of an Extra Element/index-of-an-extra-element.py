class Solution:
    def findExtra(self,a,b,n):
        #add code here
        a1 = set(a)
        b1 = set(b)
        c = a1.difference(b1)
        return a.index(list(c)[0])
#{ 
 # Driver Code Starts
if __name__ == "__main__":
    t=int(input())
    for i in range(t):
        n=int(input())
        a=list(map(int,input().split()))
        b=list(map(int,input().split()))
        print(Solution().findExtra(a,b,n))
# } Driver Code Ends