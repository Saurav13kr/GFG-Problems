#User function Template for python3
class Solution:
    def minDifference(self, N, A): 
        #code here
        arr = [0] * (N + 1)
        for i in range(N):
            arr[i + 1] = arr[i] + A[i]
        def fun(low, high):
            l, h = low, high
            while l < h:
                m = (l + h) // 2
                ls = arr[m + 1] - arr[low]
                rs = arr[high + 1] - arr[m]
                if ls >= rs:
                    h = m
                else:
                    l = m + 1
            c1, c2 = arr[l + 1] - arr[low], arr[high + 1] - arr[l + 1]
            if l > low:
                c3, c4 = arr[l] - arr[low], arr[high + 1] - arr[l]
                if abs(c1 - c2) > abs(c3 - c4):
                    return min(c3, c4), max(c3, c4)
            return min(c1, c2), max(c1, c2)
            
        ans = 10 ** 9
        for i in range(1, N - 2):
            mi1, mx1 = fun(0, i)
            mi2, mx2 = fun(i+1, N - 1)
            ans = min(ans, max(mx1, mx2) - min(mi1, mi2))
        return ans


#{ 
 # Driver Code Starts
#Initial Template for Python 3



if __name__ == '__main__': 
    t = int(input())
    for _ in range(t):
        N = int(input())
        A = list(map(int, input().strip().split()))
        ob = Solution()
        ans = ob.minDifference(N, A)
        print(ans)


# } Driver Code Ends