#{ 
 # Driver Code Starts
#Initial Template for Python 3

# } Driver Code Ends
#User function Template for python3


def stringJumper(str):
   b=len(str)
   for i in range(0,b):
       if(i%2==0):
           print(str[i], end="") ##printing character and separating characters by nothing

#{ 
 # Driver Code Starts.



def main():
    testcases = int(input()) #testcases
    while(testcases>0):
        str = (input())
        stringJumper(str)
        print()##separating testcases outputs by newlines
        testcases -= 1
        


if __name__=='__main__':
    main()
# } Driver Code Ends