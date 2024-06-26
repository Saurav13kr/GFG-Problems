//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
   vector<int> countElements(vector<int> &a, vector<int> &b, int n, vector<int> &query,
                              int q) {
        // Your code goes here;
        int mx{-1}, i;
        for(const auto& x : b){
            mx = max(mx, x);
        }
        int __freq[mx+1] = {0};
        vector<int> res;
        for(int i = 0;i<n;i++){
            __freq[b[i]]++;   
        }
        for(i = 1;i<=mx;i++){
            __freq[i] += __freq[i-1];
        }
        for(const auto& x : query){
            int val{a[x]};
            if(val >= mx){
                res.push_back(__freq[mx]);
            }else{
                res.push_back(__freq[val]);
            }
        }
        
        return res;
    }

};


//{ Driver Code Starts.

int main() {

    int t;

    cin >> t;

    while (t--) {

        int n;
        cin >> n;
        vector<int> a, b, ans;
        int input;
        for (int i = 0; i < n; i++) {
            cin >> input;
            a.push_back(input);
        }
        for (int i = 0; i < n; i++) {
            cin >> input;
            b.push_back(input);
        }
        int q;
        cin >> q;
        vector<int> query;
        for (int i = 0; i < q; i++) {
            cin >> input;
            query.push_back(input);
        }
        Solution obj;
        ans = obj.countElements(a, b, n, query, q);
        for (int i = 0; i < q; i++) {
            cout << ans[i] << endl;
        }
    }
    return 0;
}
// } Driver Code Ends