//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string removeKdigits(string s, int k) {
        int n = s.size();
        string ans;
        for(int i=0;i<n;i++){
            while(!ans.empty() && ans.back()>s[i] && k){
                ans.pop_back();
                k--;
            }
            if(s[i]!='0'||ans.size())
                ans.push_back(s[i]);
        }
        ans = ans.substr(0,max((int)ans.size()-k,0));
        return ans.size()?ans:"0";
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        int K;
        cin >> K;
        Solution obj;
        cout << obj.removeKdigits(S, K) << endl;
    }
    return 0;
}

// } Driver Code Ends