#User function Template for python3

class Item:
    def __init__(self,val,w):
        self.value = val
        self.weight = w
        
class Solution:    
    def fractionalknapsack(self, W,arr,n):
        arr.sort(key=lambda x : x.weight/x.value)
        i = 0
        profit = 0
        
        while W > 0 and i < len(arr):
            if W >= arr[i].weight :
                
                profit += arr[i].value
                W -= arr[i].weight
                
            else :
                sm_val = arr[i].value/arr[i].weight
                profit += (W*sm_val)
                W = 0
            
            i += 1
        
        return profit  # code here


#{ 
 # Driver Code Starts
#Initial Template for Python 3
import atexit
import io
import sys

#Contributed by : Nagendra Jha

class Item:
    def __init__(self,val,w):
        self.value = val
        self.weight = w
        
if __name__ == '__main__':
    test_cases = int(input())
    for cases in range(test_cases) :
        n,W = map(int,input().strip().split())
        info = list(map(int,input().strip().split()))
        arr = [Item(0,0) for i in range(n)]
        for i in range(n):
            arr[i].value = info[2*i]
            arr[i].weight = info[2*i+1]
            
        ob=Solution()
        print("%.6f" %ob.fractionalknapsack(W,arr,n))

# } Driver Code Ends