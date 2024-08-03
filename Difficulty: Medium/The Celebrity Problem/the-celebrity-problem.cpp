//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int celebrity(vector<vector<int> >& mat) {
        int n = mat.size();
        
        int i=0,j=n-1;
        while(i<j){
            // check if both person don't know each other then neither can be celebrity
            if(mat[i][j] == 0 && mat[j][i] == 0)
            {
                i++;j--;
            }
            // if i know j then i is not celebrity but j  can be
            else if(mat[i][j] == 1)i++;
            // if j knows i then j cannot but i can be
            else if(mat[j][i] == 1)j--;

        }
        
        // now i is our potential celebrity but as in question there may be no celebrity so check only for i
        for(int k=0;k<n;k++){
            if(k == i)continue; // celebrity does't know itself
            if(mat[i][k] == 1 || mat[k][i] == 0)return -1;
        }
        return i;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int> > M(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> M[i][j];
            }
        }
        Solution ob;
        cout << ob.celebrity(M) << endl;
    }
}

// } Driver Code Ends