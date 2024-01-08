//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int countMin(string s) {
        int n = s.size();
        vector<vector<int>> v(n + 1, vector<int>(n + 1, 0));
        string os = s;
        
        reverse(s.begin(), s.end());
        
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++) {
                if(os[i - 1] == s[j - 1]) v[i][j] = 1 + v[i - 1][j - 1];
                else v[i][j] = max(v[i - 1][j], v[i][j - 1]);
            }
            
        return n - v[n][n];
}
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        Solution ob;
        cout << ob.countMin(str) << endl;
    }
return 0;
}


// } Driver Code Ends