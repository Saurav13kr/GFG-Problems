//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Solution
{

    public:
    //Complete this function
    void printNos(int N)
    {
        if(N>0)
        {
            printNos(N-1);
            cout<<N<<" ";
        }
    }
};
int main()
{
    int T;
    
    //taking testcases
    cin>>T;
    
    while(T--)
    {
        int N;
        
        //input N
        cin>>N;
        Solution ob;
        //calling printNos() function
        ob.printNos(N);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends
