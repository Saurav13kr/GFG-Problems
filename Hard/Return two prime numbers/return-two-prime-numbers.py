#User function Template for python3

class Solution:
    def primeDivision(self, n):
        def isPrime(n):
            if n<=1:
                return False
            elif n==2:
                return True
            elif n%2==0:
                return False
            for i in range(3,int(n**0.5)+1,2):
                if n%i==0:
                    return False
            return True
        for i in range(2,n):
            if isPrime(i)==True:
                n1=i
                n2=n-n1
                if isPrime(n2)==True:
                    return n1,n2
                else:
                    continue


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        N = int(input())
        
        ob = Solution()
        p1, p2 = ob.primeDivision(N)
        print(p1,end=" ")
        print(p2)
# } Driver Code Ends