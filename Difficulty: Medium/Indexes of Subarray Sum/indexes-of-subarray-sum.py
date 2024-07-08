#{ 
 # Driver Code Starts
#Initial Template for Python 3

# } Driver Code Ends
#User function Template for python3
#User function Template for python3

#Function to find a continuous sub-array which adds up to a given number.
class Solution:
    def subArraySum(self, arr, n, s):
        curSum = arr[0]
        left = 0
        
        for right in range(1, n + 1):
            # Clean the previous window
            while curSum > s and left < right - 1:
                curSum -= arr[left]
                left += 1

            # Check if current window adds up to s
            if curSum == s:
                return [left + 1, right]

            # Add the next element to the window
            if right < n:
                curSum += arr[right]

        return [-1]
       

#{ 
 # Driver Code Starts.
#Initial Template for Python 3

import math

def main():
        T=int(input())
        while(T>0):
            
            NS=input().strip().split()
            N=int(NS[0])
            S=int(NS[1])
            
            A=list(map(int,input().split()))
            ob=Solution()
            ans=ob.subArraySum(A, N, S)
            
            for i in ans:
                print(i, end=" ")
                
            print()
            
            T-=1


if __name__ == "__main__":
    main()
# } Driver Code Ends