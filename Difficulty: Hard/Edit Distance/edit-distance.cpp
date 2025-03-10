//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int dp[1001][1001];
    // Function to compute the edit distance between two strings
    int solve( int i ,int j,string& s1, string& s2){
       if (i == s1.size()) return s2.size() - j;
       if (j == s2.size()) return s1.size() - i;
       if (dp[i][j]!=-1) return dp[i][j];
        if (s1[i] == s2[j]) return dp[i][j]=solve(i + 1, j + 1, s1, s2);
        else {
         int insert_op =1+( dp[i][j+1]!=-1 ?dp[i][j+1]: solve(i, j + 1, s1, s2));
         int delete_op =1+(dp[i+1][j]!=-1?dp[i+1][j]: solve(i + 1, j, s1, s2));
         int replace_op =1+(dp[i+1][j+1]!=-1?dp[i+1][j+1]: solve(i + 1, j + 1, s1, s2));
         return  dp[i][j]=min({insert_op, delete_op, replace_op});
}
        
    }
    int editDistance(string& s1, string& s2) {
        // code here
        memset( dp ,-1,sizeof(dp));
        return solve(0,0,s1,s2);
    }
};


//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        string s1;
        getline(cin, s1);
        string s2;
        getline(cin, s2);
        Solution ob;
        int ans = ob.editDistance(s1, s2);
        cout << ans << "\n";
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends