#User function template for Python

class Solution:
    # your task is to complete this function
    # function should return an integer
     def atoi(self,s):
        
        i = 1 if s[0] == '-' else 0
        for i in range(i,len(s)):
            if not ('0' <= s[i] <= '9'):
                return -1
        return int(s)


#{ 
 # Driver Code Starts
#Initial template for Python

if __name__=='__main__':
    t=int(input())
    for i in range(t):
        string = input().strip();
        ob=Solution()
        print(ob.atoi(string))
# } Driver Code Ends