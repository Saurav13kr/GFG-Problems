class Solution {
  public:
    int dfs(vector<vector<int>>& adj, int node, int dest, vector<int>& dp) {
        if(node == dest){
            return 1;
        }
        if(dp[node] != -1){
            return dp[node];
        }
        int total_paths = 0;
        for (auto u : adj[node]) {
            total_paths += dfs(adj, u, dest, dp);
            
        }
        return dp[node] = total_paths;

    }

    int countPaths(vector<vector<int>>& edges, int V, int src, int dest) {
        int cnt = 0;
        vector<bool> visited(V, false);
        vector<vector<int>> adj(V);
        vector<int> dp(V, -1);
        //dp[i] = number of paths from node i to destination node
        // dp[i==dest] = 1
        for (auto& edge : edges) 
        {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);  // Directed edge from u to v
        }

        cnt = dfs(adj, src, dest, dp);
        return cnt;
    }
};