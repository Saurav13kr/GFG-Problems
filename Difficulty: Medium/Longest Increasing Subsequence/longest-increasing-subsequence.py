class Solution:
    def lis(self, arr):
        n = len(arr)
        LIS = [1] * n
        
        for i in range(n - 1, -1, -1):
            for j in range(i + 1, n):
                if arr[j] > arr[i]:
                    LIS[i] = max(LIS[i], 1 + LIS[j])
        return max(LIS)

#{ 
 # Driver Code Starts
# Initial Template for Python 3
if __name__ == '__main__':
    for _ in range(int(input())):
        a = [int(x) for x in input().split()]
        ob = Solution()
        print(ob.lis(a))
        print("~")
# } Driver Code Ends