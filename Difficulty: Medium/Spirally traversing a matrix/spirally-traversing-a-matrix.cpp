//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int> > &matrix) {
        // code here
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> vis(n, vector<int>(m));
        vector<int> ans;
        vector<vector<int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    
        int row = 0, col = -1;
        int cnt = 0;
        while(ans.size() != n*m)
        {
            for(int i = 0; i < 4; i++){
                if(dir[i][1] == 1 || dir[i][1] == -1)
                {
                    col += dir[i][1];
                    while(col >= 0 && col < m && !vis[row][col])
                    {
                        vis[row][col] = 1;
                        ans.push_back(matrix[row][col]);
                        col += dir[i][1];
                        cnt++;
                    }
                    col = col - dir[i][1];
                }
                
                else if(dir[i][0] == 1 || dir[i][0] == -1){
                    row += dir[i][0];
                    while(row >= 0 && row < n && !vis[row][col]){
                        vis[row][col] = 1;  
                        ans.push_back(matrix[row][col]);
                        row += dir[i][0];
                        cnt++;
                    }
                    row = row - dir[i][0];
                }
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r, vector<int>(c, 0));

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix);
        for (int i = 0; i < result.size(); ++i)
            cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends