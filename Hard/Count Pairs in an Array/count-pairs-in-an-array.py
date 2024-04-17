#User function Template for python3

class Solution:    
   def countPairs(self, arr, n):
        from bisect import bisect_left
        ordered, count = [], 0
        for i in reversed(range(n)):
            ai = arr[i] * i
            j = bisect_left(ordered, ai)
            count += j
            ordered.insert(j, ai)
        return count
         # Your code goes here


#{ 
 # Driver Code Starts
#Initial Template for Python 3

def main():

    T = int(input())

    while(T > 0):
        n = int(input())
        a = [int(x) for x in input().strip().split()]
        ob= Solution()
        print(ob.countPairs(a, n))

        T -= 1


if __name__ == "__main__":
    main()
    
# } Driver Code Ends