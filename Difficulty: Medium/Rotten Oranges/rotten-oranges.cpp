//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int orangesRotting(vector<vector<int>>& mat) {
        // Code here
        int n=mat.size();
        int m=mat[0].size();
        int dr[4]={-1, 0, 1, 0};
        int dc[4]={0, 1, 0, -1};
        
        int fresh=0;
        
        queue<pair<int, int>>q;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j]==2){
                    q.push({i, j});
                }else if(mat[i][j]==1) fresh++;
            }
        }
        
        if(fresh==0) return 0;
        
        int time=0;
        
        while(!q.empty()){
            int size = q.size();
            time++;
            for(int t=0; t<size; t++){
                auto it=q.front();
                int r=it.first;
                int c=it.second;
                q.pop();
                
                for(int i=0; i<4; i++){
                    int nr=r+dr[i];
                    int nc=c+dc[i];
                    if(nr>=0 && nr<n && nc>=0 && nc<m && mat[nr][nc]==1){
                        mat[nr][nc]=2;
                        q.push({nr, nc});
                        fresh--;
                    }
                }
            }
        }
        if(fresh==0){
            return time-1;
        }else return -1;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mat(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> mat[i][j];
            }
        }
        Solution obj;
        int ans = obj.orangesRotting(mat);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends