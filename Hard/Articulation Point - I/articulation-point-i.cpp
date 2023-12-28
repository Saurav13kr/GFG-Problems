//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        // Code here
        function<void(int, vector<bool> &, vector<bool> &, vector<int> &, vector<int> &, vector<int> &)> apUtil = 
        [&](int u, vector<bool> &visited, vector<bool> &artPoint, vector<int> &discTime, vector<int> &low, vector<int> &parent) -> void {
            static int time = 0;
            int children = 0;
            visited[u] = true;
            discTime[u] = low[u] = ++time;
            for(auto it=adj[u].begin(); it!=adj[u].end(); ++it) {
                int v = *it;
                if(!visited[v]) {
                    ++children;
                    parent[v] = u;
                    apUtil(v, visited, artPoint, discTime, low, parent);
                    low[u] = min(low[u], low[v]);
                    if((parent[u] == -1 && children > 1) || (parent[u] != -1 && low[v] >= discTime[u]))
                        artPoint[u] = true;
                } else if(v != parent[u])
                    low[u] = min(low[u], discTime[v]);
            }
        };
        vector<int> res;
        vector<bool> visited(V, false);
        vector<int> discTime(V, 0);
        vector<int> low(V, 0);
        vector<int> parent(V, -1);
        vector<bool> artPoint(V, false);
        for(int i=0; i<V; ++i)
            if(!visited[i])
                apUtil(i, visited, artPoint, discTime, low, parent);
        for(int i=0; i<V; ++i)
            if(artPoint[i])
               res.push_back(i);
        if(res.size() > 0)
            return res;
        return {-1};
    }
};


//{ Driver Code Starts.

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends