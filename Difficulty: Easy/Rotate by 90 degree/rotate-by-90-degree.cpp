//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
     void rotateby90(vector<vector<int>>& mat) {
        for(int i=0;i<mat.size();++i){
            reverse(mat[i].begin(),mat[i].end());
        }
        
        for(int i=0;i<mat.size();++i){
            for(int j=i;j<mat[0].size();++j)
            {
                swap(mat[i][j],mat[j][i]);
            }
        }
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<vector<int> > matrix(n);

        for (int i = 0; i < n; i++) {
            matrix[i].assign(n, 0);
            for (int j = 0; j < n; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        ob.rotateby90(matrix);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j)
                cout << matrix[i][j] << " ";
            cout << endl;
        }

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends