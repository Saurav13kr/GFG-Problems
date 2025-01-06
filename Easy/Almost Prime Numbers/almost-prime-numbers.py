#Your task is to complete this function
#Function should print the required output in one line
#donot print new Line
def printKAlmostPrimes(k, n):
    #Code here
    primes = [2, 3, 5, 7, 11, 13]
    
    number = 2
    while n:
        fcount, temp = 0, number
        
        for prime in primes:
            while temp % prime == 0:
                temp //= prime
                fcount += 1
        
        if fcount + (temp != 1) == k:
            print(number, end=' ')
            n -= 1
        
        number += 1
if __name__=='__main__':
    t = int(input())
    for i in range(t):
        k,n = list(map(int, input().strip().split()))
        printKAlmostPrimes(k, n)
        print('')
# Contributed by: Harshit sidhwa
# } Driver Code Ends
