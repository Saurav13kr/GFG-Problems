#User function Template for python3

import numpy as np
class Solution:
    def maximumMeetings(self,n,start,end):
        start = np.array(start)
        ind = start.argsort()
        start = start[ind]
        c=0
        s=-1
        e=-1
        for i in range(n):
            if end[ind[i]]<e:
                s=start[i]
                e=end[ind[i]]
            elif start[i]>e:
                c=c+1
                s=start[i]
                e=end[ind[i]]
                    
        return c



#{ 
 # Driver Code Starts
#Initial Template for Python 3
import atexit
import io
import sys

#Contributed by : Nagendra Jha

if __name__ == '__main__':
    test_cases = int(input())
    for cases in range(test_cases) :
        n = int(input())
        start = list(map(int,input().strip().split()))
        end = list(map(int,input().strip().split()))
        ob=Solution()
        print(ob.maximumMeetings(n,start,end))
# } Driver Code Ends