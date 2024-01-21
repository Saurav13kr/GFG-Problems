//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    map<pair<int,vector<int>>,int> mp;
    int solve(int  n, vector<pair<int, int>> &edges,int i, vector<int> &vis ){
        if(i>=edges.size()){
            return 0;
        }
        if(mp.find({i,vis})!=mp.end()){
            return mp[{i,vis}];
        }
        int a =edges[i].first;
        int b = edges[i].second;
        if(vis[a]==0 && vis[b]==0){
            vis[a] = 1;
            int val = solve(n,edges,i+1,vis)+1;
            vis[a] = 0;
            vis[b] = 1;
            int val1 = solve(n,edges,i+1,vis)+1;
            vis[b] = 0;
            return mp[{i,vis}] = min(val,val1);
        }
        return mp[{i,vis}]  = solve(n,edges,i+1,vis);
    }
    
        int vertexCover(int n, vector<pair<int, int>> &edges) {
                // code here
                vector<int> vis(n+1,0);
               return solve(n,edges,0,vis);
            }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        vector<pair<int,int>> edges;
        for(int i=0;i<m;i++)
        {
            int a,b;
            cin>>a>>b;
            edges.push_back({a,b});
        }
        Solution s;
        cout<<s.vertexCover(n,edges)<<endl;
    }
    return 0;
}
// } Driver Code Ends