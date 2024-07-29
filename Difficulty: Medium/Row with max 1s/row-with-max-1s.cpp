//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
     int rowWithMax1s(std::vector<std::vector<int>> &arr) 
    {
        int max_count = 0;
        int max_index = -1;
        int r = arr.size();
        int c = arr[0].size();
        
        for(int i = 0; i < r; i++) {
            int count = 0;
            for(int j = 0; j < c; j++)
            {
                if(arr[i][j] == 1)
                    count++;
            }
            if(count > max_count)
            {
                max_count = count;
                max_index = i;
            }
        }
        
        return max_index;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int> > arr(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends