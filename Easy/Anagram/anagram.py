#User function Template for python3

class Solution:
        def isAnagram(self,a,b):
        #code here
        return True if sorted(list(a))==sorted(list(b)) else False

#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__=='__main__':
    t = int(input())
    for i in range(t):
        a,b=map(str,input().strip().split())
        if(Solution().isAnagram(a,b)):
            print("YES")
        else:
            print("NO") 
# } Driver Code Ends
