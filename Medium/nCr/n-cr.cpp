//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    int nCr(int n, int r)
    {
        if(n<r) return 0;
        if((n-r)<r)
            r = n-r;

        int M = 1e9+7;
        vector<int> row(n+1, 1);
        
        for(int i = 2; i<=n; i++){
            for(int j=min(i-1, r); j>0; j--)
            {
                row[j] = (row[j]%M + row[j-1]%M)%M;
            }
        }
        return row[r];
        
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, r;
        cin>>n>>r;
        
        Solution ob;
        cout<<ob.nCr(n, r)<<endl;
    }
    return 0;
}
// } Driver Code Ends