//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<int>> tarjans(int V, vector<int> adj[]){
        vector<vector<int>> result;
        vector<int> disc(V, -1), low(V, -1);
        vector<bool> inStack(V, false);
        stack<int> st;
        int time = 0;

        for (int i = 0; i < V; ++i)
        {
            if (disc[i] == -1)
                tarjanDFS(i, adj, disc, low, inStack, st, result, time);
        }

        // Sort the components and the array of components.
        for (vector<int> &component : result)
            sort(component.begin(), component.end());
        sort(result.begin(), result.end());

        return result;
    }

private:
    void tarjanDFS(int u, vector<int> adj[], vector<int> &disc, vector<int> &low, vector<bool> &inStack,
                   stack<int> &st, vector<vector<int>> &result, int &time)
    {
        disc[u] = low[u] = time++;
        st.push(u);
        inStack[u] = true;

        for (int v : adj[u])
        {
            if (disc[v] == -1) // If v is not visited
            {
                tarjanDFS(v, adj, disc, low, inStack, st, result, time);
                low[u] = min(low[u], low[v]);
            }
            else if (inStack[v]) // If v is in the current SCC
            {
                low[u] = min(low[u], disc[v]);
            }
        }

        // Check if u is the start of an SCC
        if (disc[u] == low[u])
        {
            vector<int> component;
            while (true)
            {
                int v = st.top();
                st.pop();
                inStack[v] = false;
                component.push_back(v);
                if (v == u)
                    break;
            }
            result.push_back(component);
        }
    }
};


//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for(int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<vector<int>> ptr = obj.tarjans(V, adj);

        for(int i=0; i<ptr.size(); i++)
        {
            for(int j=0; j<ptr[i].size(); j++)
            {
                if(j==ptr[i].size()-1)
                    cout<<ptr[i][j];
                else
                    cout<<ptr[i][j]<<" ";
            }
            cout<<',';
        }
        cout<<endl;
    }

    return 0;
}


// } Driver Code Ends