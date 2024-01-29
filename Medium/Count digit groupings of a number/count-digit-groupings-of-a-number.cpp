//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    int dp[101][901];
    int solve(int i, int prev_sum, string &s){
        if (i == s.size())
            return 1;

        if (dp[i][prev_sum] != -1)
            return dp[i][prev_sum];

        int sum = 0, ans = 0;
        for (int j = i; j < s.size(); j++)
        {
            sum += (s[j] - '0');
            if (sum >= prev_sum)
                ans += solve(j + 1, sum, s);
        }
        return dp[i][prev_sum] = ans;
    }
    int TotalCount(string str)
    {
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, str);
    }
};



//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution ob;
		int ans = ob.TotalCount(str);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends