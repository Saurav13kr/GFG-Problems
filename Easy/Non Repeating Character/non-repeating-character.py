#User function Template for python3

class Solution:
    
    def nonrepeatingCharacter(self,s):
        alpha = [0] * 26
        
        for c in s:
            alpha[ord(c) - 97] += 1
            
        
        for c in s:
            if alpha[ord(c) - 97] == 1: return c

        return '$'
    


#{ 
 # Driver Code Starts
#Initial Template for Python 3

import atexit
import io
import sys

_INPUT_LINES = sys.stdin.read().splitlines()
input = iter(_INPUT_LINES).__next__
_OUTPUT_BUFFER = io.StringIO()
sys.stdout = _OUTPUT_BUFFER

@atexit.register

def write():
    sys.__stdout__.write(_OUTPUT_BUFFER.getvalue())

if __name__=='__main__':
    t = int(input())
    for i in range(t):
        s=str(input())
        obj = Solution()
        ans=obj.nonrepeatingCharacter(s)
        if(ans!='$'):
            print(ans)
        else:
            print(-1)
            
# } Driver Code Ends