class Solution:
    def longestSubarray(self, arr):
        n = len(arr)
        left, right = [-1]*n, [n]*n
        
        stk = []
        for i in range(n-1, -1, -1):
            while(stk and arr[stk[-1]] <= arr[i]):
                stk.pop()
            if stk:
                right[i] = stk[-1]
            stk.append(i)
        stk = []
        for i in range(n):
            while(stk and arr[stk[-1]] <= arr[i]):
                stk.pop()
            if stk:
                left[i] = stk[-1]
            stk.append(i)
        maxi = 0
        for i in range(n):
            l = right[i] - left[i] - 1
            if arr[i] > l:
                continue
            maxi = max(maxi, l)
        return maxi