#User function Template for python3
import heapq

class Solution:
    def nearlySorted(self, arr, k):
        min_heap = []
        j = 0
        for i in range(len(arr)):
            heapq.heappush(min_heap, arr[i])
            if len(min_heap) > k:
                arr[j] = heapq.heappop(min_heap)
                j += 1
        while min_heap:
            arr[j] = heapq.heappop(min_heap)
            j += 1
#{ 
 # Driver Code Starts
# Initial Template for Python 3
# Position this line where user code will be pasted.
# Initial Template for Python 3

if __name__ == "__main__":
    t = int(input())
    while t > 0:
        arr = list(map(int, input().split()))
        k = int(input())
        ob = Solution()
        ob.nearlySorted(arr, k)
        print(*arr)
        # print("~")
        t -= 1
# } Driver Code Ends