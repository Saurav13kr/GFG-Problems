#User function Template for python3

class Solution:
    def findTwoElement(self, arr):
        arr1 = set(range(1, len(arr) + 1))
        repeating = []
        missing = []

        for num in arr:
            if num in arr1:
                arr1.remove(num)
            else:
                repeating.append(num)

        missing = list(arr1)
        return [repeating[0], missing[0]]
#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':

    tc = int(input())
    while tc > 0:
        n = int(input())
        arr = list(map(int, input().strip().split()))
        ob = Solution()
        ans = ob.findTwoElement(arr)
        print(str(ans[0]) + " " + str(ans[1]))
        tc = tc - 1

# } Driver Code Ends