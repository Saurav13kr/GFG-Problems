from typing import List

class Solution:
    def maximumProfit(self, prices) -> int:
        ans=0
        curmi=prices[0]
        for i in range(len(prices)-1):
            if prices[i+1]<=prices[i]:
                ans+=prices[i]-curmi
                curmi=prices[i+1]
        return ans+prices[-1]-curmi
        
#{ 
 # Driver Code Starts
#Initial Template for Python 3
if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        arr = list(map(int, input().strip().split()))
        solution = Solution()
        res = solution.maximumProfit(arr)
        print(res)

# } Driver Code Ends