#User function Template for python3

class Solution:
    def isKPartitionPossible(self, a, k):
        s = sum(a)
        if s % k != 0:
            return False
        t = s // k
        subset = [0] * k
        def fun(idx, n, subset, t):
            if idx == n:
                return True
            for i in range(k):
                if subset[i] + a[idx] <= t:
                    subset[i] += a[idx]
                    if fun(idx + 1, n, subset, t):
                        return True
                    subset[i] -= a[idx]
                    if subset[i] == 0:
                        break
            return False
        return fun(0, len(a), subset, t)
#{ 
 # Driver Code Starts


if __name__ == '__main__':
    tcs = int(input())
    for _ in range(tcs):
        N=int(input())
        arr=[int(x) for x in input().split()]
        k=int(input())
        if Solution().isKPartitionPossible(arr, k):
            print(1)
        else:
            print(0)
# } Driver Code Ends