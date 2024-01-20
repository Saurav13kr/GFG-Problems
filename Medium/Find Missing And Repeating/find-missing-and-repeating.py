#User function Template for python3

class Solution:
    def findTwoElement( self,arr, n): 
        # code here
        a = b = None
        # checking the visted element in array is already visitied then mark negative if not then +v
        for i in range(n):
            if arr[abs(arr[i])-1] < 0:
                a = abs(arr[i])
            else:
                arr[abs(arr[i])-1] = -arr[abs(arr[i])-1]
        # calculating the +v element and indexx ocrrespodence to that element will be missing number 
        for j in range(n):
            if arr[j] > 0:
                b = j+1
                break
        return a , b

#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__': 

    tc=int(input())
    while tc > 0:
        n=int(input())
        arr=list(map(int, input().strip().split()))
        ob = Solution()
        ans=ob.findTwoElement(arr, n)
        print(str(ans[0])+" "+str(ans[1]))
        tc=tc-1
# } Driver Code Ends