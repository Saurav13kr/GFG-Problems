#User function Template for python3

class Solution:
    def Maximize(self, a, n): 
        k=[]
        a.sort()
        # Complete the function
        for i in range(len(a)):
            k.append(a[i]*i) 
        l=sum(k)
        l=l%(10**9 +7)
        return l


#{ 
 # Driver Code Starts
#Initial Template for Python 3


for _ in range(0,int(input())):
    n = int(input())
    arr = list(map(int,input().strip().split()))
    ob=Solution()
    print(ob.Maximize(arr, n))
    
# } Driver Code Ends