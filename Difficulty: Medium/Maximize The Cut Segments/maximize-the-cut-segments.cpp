//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends

class Solution
{
    public:
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        vector<int> dp(n+1, 0);
        for(int i = n; i >= 0; i--){
            if(i != n && !dp[i]) continue;
            if(i>=x) dp[i-x] = max(dp[i-x], 1 + dp[i]);
            if(i>=y) dp[i-y] = max(dp[i-y], 1 + dp[i]);
            if(i>=z) dp[i-z] = max(dp[i-z], 1 + dp[i]);
        }
        return dp[0];
    }
};


//{ Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}
// } Driver Code Ends