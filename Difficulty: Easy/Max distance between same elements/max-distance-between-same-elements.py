class Solution:
    def maxDistance(self, arr):
        dic={}
        ans=0
        for i in range(len(arr)):
            if arr[i] in dic:
                ans=max(ans,i-dic[arr[i]])
            else:
                dic[arr[i]]=i
        return ans;
        
#{ 
 # Driver Code Starts
if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        arr = list(map(int, input().split()))
        ob = Solution()
        print(ob.maxDistance(arr))

# } Driver Code Ends