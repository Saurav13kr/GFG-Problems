//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    long long sequence(int n){
        // code here
        long long res = 0;
        long long num = 1;
        long long mod = 1e9+7;
        
        for(long long i=1;i<=n;i++){
            long long prod = 1;
            for(long long j=0;j<i;j++){
                prod = (prod * num)%mod;
                num++;
            }
            
            res = (res + prod)%mod;
        }
        
        
        return res;
    }
};




//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.sequence(N)<<endl;
    }
    return 0;
}
// } Driver Code Ends