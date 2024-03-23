//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
   vector<int> Series(int n) {
        // Code here
        vector<int> v1;
        v1.push_back(0);
        v1.push_back(1);
        for(int i=1;i<n;i++){
            v1.push_back((v1[i]+v1[i-1])%(int)(1e9 + 7));
        }
        return v1;
   }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;

        vector<int> ans = obj.Series(n);
        for (auto x : ans) cout << x << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends