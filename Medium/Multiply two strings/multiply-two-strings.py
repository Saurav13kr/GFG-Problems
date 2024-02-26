#User function Template for python3

class Solution:
    def multiplyStrings(self,s1,s2):
        
        d={}
        
        x = 48
        for i in range(10):
            d[str(i)] = x
            x+=1
        num1=0
        p=0
        sign =0
        
        for i in s1[::-1]:
            if i=='-':
                sign = 1
                break
            num1=num1+(pow(10,p)*(d[i]-d['0']))
            p+=1
        if sign ==1:
            num1 = -num1
        sign = 0
        num2=0
        p=0
        for i in s2[::-1]:
            if i=='-':
                sign=1
                break
            num2=num2+(pow(10,p)*(d[i]-d['0']))
            p+=1
        if sign==1:
            num2=-num2
        return num1*num2

#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == "__main__":
    t=int(input())
    for i in range(t):
        a,b=input().split()
        print(Solution().multiplyStrings( a.strip() , b.strip() ))

# } Driver Code Ends