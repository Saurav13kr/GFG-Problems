//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int solve(int first,int p,int q){
        if(q==0){
            return 1;
        }
        if(q<0 || first>p){
            return 0;
        }
        return solve(first+1,p,q)+solve(2*first,p,q-1);
    }
    int numberSequence(int p, int q){
        return solve(1,p,q);
    }
};



//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int m, n;
        cin>>m>>n;
        
        Solution ob;
        cout<<ob.numberSequence(m, n)<<endl;
    }
    return 0;
}
// } Driver Code Ends