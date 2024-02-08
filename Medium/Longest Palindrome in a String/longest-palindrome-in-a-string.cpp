//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string longestPalin (string S) {
        int n=S.size();
        string ans="";
        int resLen=0;
        for(int i=0;i<n;i++){


           /* odd length palindrome check*/


           int l=i,r=i;
           while(l>=0 && r<n && S[l]==S[r]){
               if(r-l+1 > resLen){
                   ans=S.substr(l,r-l+1);
                   resLen=r-l+1;
               }
               l-=1;
               r+=1;
           }


           /* even length palindrome check*/


           l=i,r=i+1;
           while(l>=0 && r<n && S[l]==S[r]){
               if(r-l+1 > resLen){
                   ans=S.substr(l,r-l+1);
                   resLen=r-l+1;
               }
               l-=1;
               r+=1;
           }
        }
        return ans;
    
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends