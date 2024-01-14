//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
      int knapSack(int maxWeight, int wt[], int val[], int n) 
    { 
       // Your code here
         vector<int> dp(maxWeight + 1, 0);
  if (wt[0] <= maxWeight)
    for (int i = wt[0]; i <= maxWeight; i++)
      dp[i] = val[0];
  for (int ind = 1; ind < n; ind++) {
    for (int maxW = maxWeight; maxW >= 0; maxW--) {
      int notTake = 0 + dp[maxW];
      int Take = INT_MIN;
      if (wt[ind] <= maxW)
        Take = val[ind] + dp[maxW - wt[ind]];

      dp[maxW] = max(Take, notTake);
    }
  }

  return dp[maxWeight];
       
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends