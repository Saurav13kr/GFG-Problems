#User function Template for python3

class Solution:
    def getLastDigit(self, a, b):
        # code here 
        if b=='0' or a=='1':
            return 1
        elif b=='1':
            return a
        b = int(b)%4
        if b==0:
            b=4
        a=int(a[-1])
        return (a**b)%10

#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__': 
    t = int (input ())
    for _ in range (t):
        a,b=map(str,input().split())
        
        ob = Solution()
        print(ob.getLastDigit(a,b))
# } Driver Code Ends