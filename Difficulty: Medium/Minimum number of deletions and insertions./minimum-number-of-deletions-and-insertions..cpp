//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
	public:
	vector<vector<int>> dp;
	int solve(string& str1, string& str2, int i, int j) {
	    if(i >= str1.size()) {
	        return (str2.size() - j);
	    }
	    if(j >= str2.size()) {
	        return (str1.size() - i);
	    }
	    if(dp[i][j] != -1) return dp[i][j];
	    int ans = INT_MAX;
	    if(str1[i] == str2[j]) 
	    {
	        ans = min(ans, solve(str1, str2, i + 1, j + 1));
	    }
	    ans = min(ans, solve(str1, str2, i + 1, j) + 1);
	    ans = min(ans, solve(str1, str2, i, j + 1) + 1);
	    
	    return dp[i][j] = ans;
	}
	int minOperations(string str1, string str2) 
	{   
	    int n = str1.size(), m = str2.size();
	    dp.assign(n, vector<int>(m, -1));
	    return solve(str1, str2, 0, 0);
	} 
};




//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends