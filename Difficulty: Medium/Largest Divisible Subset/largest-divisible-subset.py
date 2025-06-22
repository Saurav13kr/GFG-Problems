class Solution:
    def largestSubset(self, arr):
        if not arr:
            return []
        
        arr.sort()
        n = len(arr)
        
        dp = [[num] for num in arr]

        for i in range(n):
            for j in range(i):
                if arr[i] % arr[j] == 0:
                    if len(dp[j]) + 1 > len(dp[i]):
                        dp[i] = dp[j] + [arr[i]]
                    elif len(dp[j]) + 1 == len(dp[i]):
                        dp[i] = max(dp[i], dp[j] + [arr[i]])
        
        max_len = max(len(sub) for sub in dp)
        candidates = [sub for sub in dp if len(sub) == max_len]
        return max(candidates)