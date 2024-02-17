class Solution:
    def isMaxHeap(self,arr,n):
        # Your code goes here 
        for i in range(n):
            l=2*i+1
            r=2*i+2
            if l<n:
                if arr[i] < arr[l]:
                    return 0
            if r<n:
                if arr[i]<arr[r]:
                    return 0
        return 1


#{ 
 # Driver Code Starts
if __name__ =='__main__':
    t= int(input())
    for tcs in range(t):
        n=int(input())
        arr=[int(x) for x in input().split()]
        ob=Solution()
        print(int(ob.isMaxHeap(arr,n)))
# } Driver Code Ends