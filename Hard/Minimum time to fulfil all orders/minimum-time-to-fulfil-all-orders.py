
from typing import List
import math
class Solution:
    def findMinTime(self, n : int, l : int, arr : List[int]) -> int:
        # code here
        def find(t):
            donuts=0
            for i in range(len(arr)):
                x=(t*2)//arr[i]                # (d*(d+1))//2 *arr[i]<=t
                d=(-1+math.sqrt(1+4*x))//2      # take (2*t)//arr[i]=x
                donuts+=d                        # d(d+1)=x
            return donuts
        l=0
        r=10**9
        while l<=r:
            mid=(l+r)//2
            ans=find(mid)
            if(ans>=n):
                r=mid-1
            else:
                l=mid+1
        return l



#{ 
 # Driver Code Starts

class IntArray:
    def __init__(self) -> None:
        pass
    def Input(self,n):
        arr=[int(i) for i in input().strip().split()]#array input
        return arr
    def Print(self,arr):
        for i in arr:
            print(i,end=" ")
        print()


if __name__=="__main__":
    t = int(input())
    for _ in range(t):
        
        n = int(input())
        
        
        l = int(input())
        
        
        arr=IntArray().Input(l)
        
        obj = Solution()
        res = obj.findMinTime(n, l, arr)
        
        print(res)
        

# } Driver Code Ends