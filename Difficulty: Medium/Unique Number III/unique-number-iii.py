#User function Template for python3

from collections import Counter
class Solution:
    def getSingle(self, arr):
        # code here 
        c = Counter(arr)
        
        for i in c.keys():
            if c[i] == 1:
                return i
#{ 
 # Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        arr = list(map(int, input().split()))
        ob = Solution()
        ans = ob.getSingle(arr)
        print(ans)
        print("~")
# } Driver Code Ends