#User function Template for python3

class Solution:
    def pairAndSum(self, n, arr):
        #we initially take sum as 0
        sum=0
        #then we iterate through each bit position
        for i in range(32):
           
            count=0
            #now we iterate through the array using j
            for j in arr:
                 # Check if the bit at position i is set (1) in the current element
                if j&(1<<i):
                    # Increment the count if the bit is set
                    count+=1
            #calculate the sum contributed by the bit position
            sum+=count*(count-1)//2*(1<<i)
        return sum

#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__=='__main__':
    t=int(input())
    for _ in range(t):
        N=int(input())
        Arr=list(map(int,input().strip().split(' ')))
        ob=Solution()
        print(ob.pairAndSum(N,Arr))
# } Driver Code Ends