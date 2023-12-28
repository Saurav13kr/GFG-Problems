//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool palindrome(string str,int i,int j)
    {
       while(i<=j)
       {
           if(str[i]!=str[j]) return false;
           i++;
           j--;
       }
        return true;
    }
    int palindromicPartition(string str)
    {
        int n=str.length();
      vector<int> dp(n,INT_MAX);
      
      for(int i=n-1;i>=0;i--) //for every index to update dp
      {
         
          for(int j=i;j<n;j++)//to check for palindrome
          {
            if(palindrome(str,i,j))//if substring i to j is palindrome
            {
                int len=j-i+1;
                if(i+len>=n)
                   dp[i]=0;
                else
                   dp[i]=min(dp[i],dp[i+len]+1);
                //cout<<dp[i]<<",";
            }
          }
         // cout<<endl;
      }

      return dp[0];
    }
};




//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends