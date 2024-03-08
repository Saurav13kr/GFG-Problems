//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int shotestPath(vector<vector<int>> mat, int m, int n, int k) {
        vector<vector<int>> vis(m, vector<int>(n,-1));
        queue<vector<int>> q;
        q.push({0,0,0,k});
        
        int lrow[4] = {-1,0,0,1};
        int lcol[4] = {0,1,-1,0};
        
        vis[0][0] = k;
        
        while(!q.empty()){
            vector<int> temp = q.front();
            q.pop();
            int row = temp[0];
            int col = temp[1];
            int d = temp[2];
            int currk = temp[3];
            
            if(row==m-1 && col==n-1){
                return d;
            }
            
            for(int i=0;i<4;i++){
                int nrow = row + lrow[i];
                int ncol = col + lcol[i];
                
                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && vis[nrow][ncol]< currk && mat[nrow][ncol]==0){
                    q.push({nrow,ncol,d+1,currk});
                    vis[nrow][ncol] = currk;
                }
                else if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && vis[nrow][ncol]< currk && mat[nrow][ncol]==1 && currk > 0){
                    q.push({nrow,ncol,d+1,currk-1});
                    vis[nrow][ncol] = currk-1;
                }
            }
        }
        return -1;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, k, x;
        
        cin>>n>>m>>k;
        vector<vector<int>> mat;
    
        for(int i=0; i<n; i++)
        {
            vector<int> row;
            for(int j=0; j<m; j++)
            {
                cin>>x;
                row.push_back(x);
            }
            mat.push_back(row);
        }

        Solution ob;
        cout<<ob.shotestPath(mat,n,m,k);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends