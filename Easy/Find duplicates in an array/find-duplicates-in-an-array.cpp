//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
  public:
    vector<int> duplicates(long long arr[], int n) {
        set<int> ans;
        
        sort(arr, arr + n);
        
        for(int i = 0; i < n - 1; i++) {
            if(arr[i] == arr[i + 1]) {
                ans.insert(arr[i]);
                
            }
        }
        
        if(ans.empty()) {
            ans.insert(-1);
        }
        
        vector<int> output(ans.begin(), ans.end());
        
        return output;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n;
        cin >> n;
        long long a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution obj;
        vector<int> ans = obj.duplicates(a, n);
        for (int i : ans) cout << i << ' ';
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends