//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
    
int find(int *arr, int i, int n, vector<int>& dp){
    if(i>=n) return 0;
    if(dp[i]!=-1) return dp[i];
    int ans;
    ans=arr[i] + find(arr, i+2, n, dp);
    if(i+1 < n) ans= max(ans, arr[i+1] + find(arr, i+3, n, dp));
    
    dp[i] = ans;
    return dp[i];
}
int findMaxSum(int *arr, int n) {
    vector<int> dp(n+1, -1);
    return find(arr, 0, n, dp);
 
}
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends