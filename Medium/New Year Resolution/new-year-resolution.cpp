//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    
    public:
    bool dfs(int i,int sum,int n,int coins[],vector<vector<int>>&dp){
        if(sum>0 and (sum%24==0 or sum%20==0 or sum==2024)) return true;
        if(i==n) return false;
        if(dp[i][sum]!=-1) return dp[i][sum];
        return dp[i][sum]=dfs(i+1,sum,n,coins,dp) or dfs(i+1,sum+coins[i],n,coins,dp);
    }
    int isPossible(int n, int coins[]) 
    {
        vector<vector<int>>dp(n,vector<int>(2025,-1));
        return dfs(0,0,n,coins,dp);
    }
};




//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        int coins[N];
        for(int i=0 ; i<N ; i++)
            cin>>coins[i];

        Solution ob;
        cout << ob.isPossible(N,coins) << endl;
    }
    return 0;
}
// } Driver Code Ends