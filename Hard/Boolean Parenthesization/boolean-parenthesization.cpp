//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

#define ll long long
#define mod 1003
class Solution{
public:
    int possibleTrues(int i,int j,bool isTrue,string &s,vector<vector<vector<ll>>>&dp)
    {
      if(i>j)return 0;
      
      if(i==j)
      {
        if(isTrue)
        {
            return s[i]=='T';
        }
        else
        {
            return s[i]=='F';
        }
      }
      if(dp[i][j][isTrue]!=-1)return dp[i][j][isTrue];
      ll ways= 0;
      for(int ind=i+1;ind<=j-1;ind+=2)
      {
        ll LSPT=possibleTrues(i,ind-1,1,s,dp);
        ll RSPT=possibleTrues(ind+1,j,1,s,dp);
        ll LSPF=possibleTrues(i,ind-1,0,s,dp);
        ll RSPF=possibleTrues(ind+1,j,0,s,dp);

        if(s[ind]=='&')
        {
           if(isTrue)
           {
             ways=(ways+(LSPT*RSPT)%mod)%mod;
           }
           else
           {
            ways=(ways+(LSPT*RSPF)%mod+(LSPF*RSPT)%mod+(LSPF*RSPF)%mod)%mod;
           }
        }
        else if(s[ind]=='|')
        {
           if(isTrue)
           {
            ways=(ways+(LSPT*RSPF)%mod+(LSPF*RSPT)%mod+(LSPT*RSPT)%mod)%mod;
           }
           else
           {
            ways=(ways+(LSPF*RSPF)%mod)%mod;
           }
        }
        else if(s[ind]=='^')
        {
        if(isTrue)
        {
            ways=(ways+(LSPF*RSPT)%mod+(LSPT*RSPF)%mod)%mod;
        }
        else
        {
            ways=(ways+(LSPT*RSPT)%mod+(LSPF*RSPF)%mod)%mod;
        }
        }
      }
      return dp[i][j][isTrue]=ways;
      
    }
    int countWays(int N, string S)
    {
        vector<vector<vector<ll>>>dp(N,vector<vector<ll>>(N,vector<ll>(2,-1)));

       return possibleTrues(0,N-1,1,S,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends