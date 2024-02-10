#User function Template for python3

class Solution:
     def numberOfPath (self, n, k, arr):
        # code here
        dp=[]
        for i in range(n):
            c=[]
            for j in range(n):
                d=[]
                for k in range(k+1):
                    d.append(-1)
                c.append(d)
            dp.append(c)
        def trav(i,j,su):
            if(i>=n or j>=n or su>k):
                return 0
            if(dp[i][j][su]!=-1):
                return dp[i][j][su]
            if(i==n-1 and j==n-1 and k==su+arr[i][j]):
                return 1
            one=trav(i+1,j,su+arr[i][j])
            two=trav(i,j+1,su+arr[i][j])
            dp[i][j][su]=one+two
            return (dp[i][j][su])
        return trav(0,0,0)


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__': 
    ob = Solution()
    t = int (input ())
    for _ in range (t):
        k= int(input())
        n=int(input())
        l = list(map(int, input().split()))
        arr = list()
        c=0
        for i in range(0, n):
            temp = list()
            for j in range(0, n):
                temp.append(l[c])
                c += 1
            arr.append(temp)
        ans = ob.numberOfPath(n, k, arr);
        print(ans)


# } Driver Code Ends