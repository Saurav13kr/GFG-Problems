//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int smallestSubstring(string S) {
        // Code here
        int a[3]={},j=0,ans=INT_MAX,cnt=0,n=S.length();
        
        for(int i=0;i<n;i++){
            if(a[S[i]-'0']==0)cnt++;
            a[S[i]-'0']++;
            
            while(cnt==3){
                ans=min(ans,i-j+1);
                a[S[j]-'0']--;
                if(a[S[j]-'0']==0)cnt--;
                j++;
            }
        }
        
        return ans==INT_MAX?-1:ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.smallestSubstring(S);
        cout << endl;
    }
}
// } Driver Code Ends