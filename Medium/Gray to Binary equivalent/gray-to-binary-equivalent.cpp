//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int grayToBinary(int n)
{
        bool a[32]={};
        int i=31;
        while(n){
            a[i]=n%2;
            n/=2;
            i--;
        }
        bool prev=a[0];
        for(int i=1;i<32;i++){
            a[i]=(prev^a[i]);
            prev=a[i];
        }
        int res=0;
        for(int i=31;i>=0;i--){
             if(a[i]){
                  res+=pow(2,(31-i));
             }
        }
        return res;
        
    }
};

int main()
{
    int t,n;
    cin>>t;//testcases
    while(t--)
    {
        cin>>n;//initializing n
        
        Solution ob;
        //calling function grayToBinary()
       cout<< ob.grayToBinary(n)<<endl;
    }
}

// } Driver Code Ends
