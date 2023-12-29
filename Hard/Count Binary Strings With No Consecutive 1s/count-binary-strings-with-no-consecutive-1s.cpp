//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    #define ll long long int
    ll mod=1000000007;
    
    vector<vector<ll>> multiply(vector<vector<ll>>& m1,vector<vector<ll>>& m2){
        ll a=((m1[0][0]*m2[0][0])%mod+(m1[0][1]*m2[1][0])%mod)%mod;
        ll b=((m1[0][0]*m2[0][1])%mod+(m1[0][1]*m2[1][1])%mod)%mod;
        ll c=((m1[1][0]*m2[0][0])%mod+(m1[1][1]*m2[1][0])%mod)%mod;
        ll d=((m1[1][0]*m2[0][1])%mod+(m1[1][1]*m2[1][1])%mod)%mod;
        m1[0][0]=a;m1[0][1]=b;
        m1[1][0]=c;m1[1][1]=d;
        return m1;
    }
    
    vector<vector<ll>> power(vector<vector<ll>>& m1,ll n){
        vector<vector<ll>> mat {{1,1},{1,0}};
        if(n==1){
            return mat;
        }
        if(n%2){
            vector<vector<ll>> res=power(m1,n-1);
            return multiply(res,mat);
        }
        vector<vector<ll>> res1=power(m1,n/2);
        return multiply(res1,res1);
    }
    
    int solve(ll n){
        vector<vector<ll>> mat {{1,1},{1,0}};
        mat=power(mat,n-1);
        return mat[0][0];
    }
    
    int countStrings(long long int n) {
        return solve(n+2);
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long int N;
        cin >> N;
        Solution obj;
        cout << obj.countStrings(N) << endl;
    }
}
// } Driver Code Ends