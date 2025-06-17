class Solution:
    def minimumCoins(self, A, k):
        A.sort()
        n, pre = len(A), [0]
        for x in A: pre.append(pre[-1] + x)
        res, j = pre[-1], 0
        for i in range(n):
            while j < n and A[j] <= A[i] + k: j += 1
            large = pre[-1] - pre[j] - (n - j) * (A[i] + k)
            res = min(res, pre[i] + (large if j < n else 0))
        return res