class Solution:
    def canSplit(self, arr):
        pref = [0]*(len(arr)+1)
        suff = [0]*(len(arr)+1)
        suff[0] = sum(arr)
        for i in range(len(arr)):
            pref[i+1]=pref[i]+arr[i] 
            suff[len(arr)-i-1] = suff[len(arr)-i]+arr[len(arr)-i-1]
        for i in range(len(arr)):
            if pref[i] == suff[i]:
                return True 
        return False



#{ 
 # Driver Code Starts
if __name__ == "__main__":
    import sys
    input = sys.stdin.read
    data = input().splitlines()

    t = int(data[0])
    index = 1
    for _ in range(t):
        arr = list(map(int, data[index].split()))
        index += 1

        obj = Solution()
        res = obj.canSplit(arr)
        if (res):
            print("true")
        else:
            print("false")

# } Driver Code Ends